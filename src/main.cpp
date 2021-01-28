#include "game.hpp"

int main(int argc, char** argv) {
  Game game;
  bool isSuccessful = game.init();
  if(isSuccessful) {
    game.runLoop();
  }
  game.shutdown();
  return 0;
}
