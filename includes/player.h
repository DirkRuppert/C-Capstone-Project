/**
 * Implementation of class Player
 * 
 * Player is a game object that can be moved through the level by arrow keys
 * 
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "SDL.h"
#include "../includes/gameObject.h"

class Player : public GameObject
{
 public:
  Player(int playerID, int posX, int posY, std::shared_ptr<Map> map);
  void SetDirection(int direction);

  void Update();

  bool alive{true};
  
 private:
  int _direction { -1 };
  
};

#endif