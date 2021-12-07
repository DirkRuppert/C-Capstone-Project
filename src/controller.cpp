#include "../includes/controller.h"
#include <iostream>
#include "SDL.h"
#include "../includes/player.h"

/** handles the keyboard key input and translate the arrow keys to direction index
*
*   map directions are defined as directions[4][2] {{-1,0}, {0,-1}, {1,0}, {0,1}};
*/
int Controller::HandleInput(bool &running) const 
{
  int direction = -1; 

  SDL_Event e;
  while (SDL_PollEvent(&e)) 
  {
    if (e.type == SDL_QUIT) 
    {
      running = false;
    } 
    else if (e.type == SDL_KEYDOWN) 
    {
      switch (e.key.keysym.sym) 
      {
        case SDLK_UP:
          direction = 1; // direction index up
          break;

        case SDLK_DOWN:
          direction = 3; // direction index down
          break;

        case SDLK_LEFT:
          direction = 0; // direction index left
          break;

        case SDLK_RIGHT:
          direction = 2; // directin index right
          break;
        
        default:
          direction = -1; // no direction index

      }
    }
  }
  return direction;
}

