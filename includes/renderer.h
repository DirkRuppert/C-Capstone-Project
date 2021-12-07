/**
 * Implementation of class Renderer
 * 
 * Renderer handles the grafical visualisation of the map and game objects and the game in general
 * 
 */

#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <memory>
#include "player.h"
#include "gameObject.h"
#include "map.h"
#include "SDL.h"



class Renderer 
{
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(vector<std::shared_ptr<GameObject>> gameObjects);
  void RenderMap(std::shared_ptr<Map> map);
  void RenderGameObject(std::shared_ptr<GameObject> &gameObject);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif