#include "game.hpp"

const int thickness = 15;

bool Game::init() {
  int sdlResult = SDL_Init(SDL_INIT_VIDEO);
  if(sdlResult != 0) {
    SDL_Log("There was an error with the program:\n%s\nShutting down, дебил...\n", SDL_GetError());
    return false;
  }
  mWindow = SDL_CreateWindow("CPlusPlusNerd's Pong", 100, 100, 640, 480, 0);
  renderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  return true;
}

void Game::handleInput() {

  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        isRunning = false;
        break;
    }

    const Uint8* kState = SDL_GetKeyboardState(NULL);
    if (kState[SDL_SCANCODE_ESCAPE] || kState[SDL_SCANCODE_Q]) {
      isRunning = false;
    }

    paddleDir = 0;
    if (kState[SDL_SCANCODE_W]) {
      paddleDir -= 1;
    } else if (kState[SDL_SCANCODE_S]) {
      paddleDir += 1;
    }
  }
}

void Game::update() {
  tickCount = SDL_GetTicks();

  while(!SDL_TICKS_PASSED(SDL_GetTicks(), tickCount+16));

  float tickTime = (SDL_GetTicks() - tickCount) / 1000.0f;

  if(tickTime > 0.05f) {
    tickTime = 0.05f;
  }

  if(paddleDir != 0) {
    paddle1Pos.y += paddleDir * 300.00f * tickTime;
    if(paddle1Pos.y < (50 - height/2.0f + thickness)) {
      paddle1Pos.y = 50 - height/2.0f + thickness;
    } else if(paddle1Pos.y > (450.00f - height/2.0f - thickness)) {
      paddle1Pos.y = 450.00f - height/2.0f - thickness;

    }
  }

  ballPos.x += ballVel.x * tickTime;
  ballPos.y += ballVel.y * tickTime;
}

void Game::output() {

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_Rect wall{0, 0, 1024, thickness};
  SDL_Rect wall1{0, 465, 1024, thickness}; // thickness = 15px;

  SDL_Rect ball{
    static_cast<int>(ballPos.x - thickness/2),
    static_cast<int>(ballPos.y - thickness/2),
    thickness,
    thickness
  };

  SDL_Rect paddle1{
    static_cast<int>(paddle1Pos.x+30 - thickness/2),
    static_cast<int>(paddle1Pos.y - thickness/2),
    thickness,
    height
  };
  SDL_RenderFillRect(renderer, &wall);
  SDL_RenderFillRect(renderer, &ball);
  SDL_RenderFillRect(renderer, &paddle1);
  SDL_RenderFillRect(renderer, &wall1);
  SDL_RenderPresent(renderer);
}

void Game::shutdown() {
  SDL_DestroyWindow(mWindow);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

void Game::runLoop() {
  while(isRunning) {
    handleInput();
    update();
    output();
  }
}
