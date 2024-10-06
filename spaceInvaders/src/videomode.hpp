#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "eventManager.hpp"
#include "font.hpp"
#include "globals.hpp"
#include "logger.hpp"
#include "music.hpp"
#include "sceneFactory.hpp"
#include "sceneInterface.hpp"
#include "sound.hpp"
#include "surface.hpp"
#include "texture.hpp"

#include <memory>

namespace si
{
static std::shared_ptr<SceneInterface> currentScene = nullptr;

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