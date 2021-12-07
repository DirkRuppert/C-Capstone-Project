#include <iostream>
#include "../includes/controller.h"
#include "../includes/game.h"
#include "../includes/renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{2};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight, renderer);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.getScore() << "\n";
  std::cout << "Size: " << game.getSize() << "\n";
  return 0;
}