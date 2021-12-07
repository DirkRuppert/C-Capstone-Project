#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include <memory>
#include <condition_variable>
#include <deque>
#include <mutex>
#include <future>

#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "player.h"
#include "level.h"
#include "ghost.h"
#include "map.h"
#include "updateHandler.h"

using std::vector;

/**
 * Implementation of class MessageQueue
 * 
 * MessageQueue handles user input by arrow keys and translate the key information to direction
 * 
 */ 

template <class T>
class MessageQueue
{
  public:
    T receive();
    void send(T &&msg);

    private:
    std::mutex _mutex;
    std::condition_variable _condition;
    std::deque<T> _queue;
};


/**
 * Implementation of class Game
 * 
 * Game is the class for general game handling and game control
 * 
 */ 
class Game 
{
 public:
  Game(std::size_t grid_width, std::size_t grid_height, Renderer &renderer);

  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int getScore() const;
  int getSize() const;

  // vector of ghosts
  vector<std::shared_ptr<Ghost>> ghosts;

  // vector of game objects
  vector<std::shared_ptr<GameObject>> gameObjects;

 private:

  void Update();

  std::shared_ptr<Player> player;
  std::shared_ptr<Map> map;
  std::shared_ptr<UpdateHandler> updateHandler;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  std::mutex _mutex;

  int score{0};
  int _numberOfGhosts { 3 };

  
};

#endif