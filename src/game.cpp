#include "../includes/game.h"
#include <iostream>
#include "SDL.h"
#include <algorithm>

template <typename T>
T MessageQueue<T>::receive()
{
  std::unique_lock<std::mutex> uLock(_mutex);
  _condition.wait(uLock, [this]
  {
    return !_queue.empty();
  });

  T msg = std::move(_queue.back());
  _queue.pop_back();

  return msg;
}

template <typename T>
void MessageQueue<T>::send(T &&msg)
{
  std::lock_guard<std::mutex> uLock(_mutex);

  _queue.push_back(std::move(msg));

  _condition.notify_one();
}

/** Constructor
*/
Game::Game(std::size_t grid_width, std::size_t grid_height, Renderer &renderer)
  : engine(dev()),
    random_w(0, static_cast<int>(grid_width -1)),
    random_h(0, static_cast<int>(grid_height -1))
{
  // creating the map / level
  map = std::shared_ptr<Map>(new Map());
  
  // create the update handler instance
  updateHandler = std::make_shared<UpdateHandler>();

  // create ghost_count number of ghost instances and add them to the game object vector
  for (size_t ghost_count = 0; ghost_count < _numberOfGhosts; ghost_count++)
  {
    gameObjects.push_back(std::make_shared<Ghost>(ghost_count, 5,5, map, updateHandler));
  }

  // create player instance and add this to game object vector
  player = std::make_shared<Player>(0, 1, 1, map);
  gameObjects.push_back(player);
}

/** the game loop
*/
void Game::Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration) 
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  //rendering the map
  renderer.RenderMap(map);

  // bring ghosts to life
  for (auto go : gameObjects)
  {
    if (go->GetType() == ObjectType::objGhost)
    {
      // cast gameObject to Ghost
      std::shared_ptr<Ghost> ghost = std::dynamic_pointer_cast<Ghost>(go);
      ghost->BringToLife(); // start haunting thread for each ghost
    }
  };

  while (running) 
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    
    frame_start = SDL_GetTicks();

    renderer.Render(gameObjects);

    // handling the keyboard input and store the player direction
    int playerDirection = controller.HandleInput(running);

    // only when all ghosts have calculated their new location
    if (updateHandler->getWaitingGhostsCount() == _numberOfGhosts)
    {
      player->SetDirection(playerDirection); // setting the direction to move for player avatar
      player->Update(); // update player position
      updateHandler->processGhostQueue(); // process queue of waiting ghosts für ghost position update
    }

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}


int Game::getScore() const { return score; }
int Game::getSize() const { return 0; }