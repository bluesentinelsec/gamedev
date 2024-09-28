#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "font.hpp"
#include "globals.hpp"
#include "music.hpp"
#include "sound.hpp"
#include "surface.hpp"
#include "texture.hpp"

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

    sdlSurface backgroundSurf;
    sdlTexture backgroundTex;
    sdlFont uiFont;
    Sound sound;
    Music music;
};
}; // namespace si