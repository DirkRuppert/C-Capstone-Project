#include "../includes/renderer.h"
#include <iostream>
#include <string>
#include <SDL_image.h>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) 
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", /*SDL_WINDOWPOS_CENTERED*/ 10,
                                /*SDL_WINDOWPOS_CENTERED*/ 10, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() 
{
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

/** renders the game objects
*
* param gameObject     vector with game object pointers
*
*/
void Renderer::Render(vector<std::shared_ptr<GameObject>> gameObjects) 
{
  // render all game objects
  for (auto gameOject : gameObjects)
  {
     RenderGameObject(gameOject);
  }
}

/** renders a single game objects
*
* param gameObject     pointer to game 
*
*/
void Renderer::RenderGameObject(std::shared_ptr<GameObject> &gameObject)
{
  int blockSize = 20;

  SDL_Rect currentRect;
  SDL_Rect newRect;

  // deleting current (=old) gameObject position
  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00, 0x00, 0x00);
  int xC = gameObject->GetCurrentLocation().GetX();
  currentRect.x = xC * blockSize;
  int yC = gameObject->GetCurrentLocation().GetY();
  currentRect.y = yC * blockSize;
  currentRect.w = blockSize;
  currentRect.h = blockSize;
  SDL_RenderFillRect(sdl_renderer, &currentRect);
  SDL_RenderPresent(sdl_renderer);

  // drawing new gameObject position, depending on gameObject colour settings
  SDL_SetRenderDrawColor(sdl_renderer, gameObject->getRColour(), gameObject->getGColour(), gameObject->getBColour(), gameObject->getAColour());
  int x = gameObject->GetNewLocation().GetX();
  newRect.x = x * blockSize;
  int y = gameObject->GetNewLocation().GetY();
  newRect.y = y * blockSize;
  newRect.w = blockSize;
  newRect.h = blockSize;
  SDL_RenderFillRect(sdl_renderer, &newRect);
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::RenderMap(std::shared_ptr<Map> map)
{
  int originX = 0;
  int originY = 0;

  int wallBlockSize = 20;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);
  
  // Render map
  vector<vector<MapLocation>> mapLocations = map->GetMapLocations();

  for (int i = 0; i < mapLocations.size(); i++)
  {
    for (int j = 0; j < mapLocations[0].size(); j++)
    {
      // only drawing walls 
      if (mapLocations[i][j].GetType() == MapLocationType::eWall)
      {
        SDL_Rect wallBlock;
        SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00, 0xFF, 0x00);
        wallBlock.x = (i * wallBlockSize);
        wallBlock.y = (j * wallBlockSize);
        wallBlock.w = wallBlockSize;
        wallBlock.h = wallBlockSize;
        SDL_RenderFillRect(sdl_renderer, &wallBlock);
        SDL_RenderPresent(sdl_renderer);
      }
    }
  }

  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) 
{
  std::string title{"Player Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

