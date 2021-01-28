#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <SDL2/SDL.h>

struct Vector2 {
  float x;
  float y;
};

class Game {
public:
  bool init();
  void shutdown();
  void runLoop();
private:
  void handleInput();
  void update();
  void output();
  SDL_Window *mWindow;
  bool isRunning;
  SDL_Renderer *renderer;
  Uint32 tickCount = 0;

  Vector2 ballPos;
  Vector2 ballVel;
  Vector2 paddle1Pos;
  Vector2 paddle2Pos;
  int paddleDir;
  int height = 90;
};
