#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "globals.hpp"

namespace si
{
class VideoMode
{
  public:
    VideoMode();
    ~VideoMode();
    bool Update();

  private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    bool isRunning = true;
};
}; // namespace si