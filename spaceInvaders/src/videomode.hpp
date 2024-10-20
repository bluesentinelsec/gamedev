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

#include <chrono>
#include <memory>

namespace si
{
static std::shared_ptr<SceneInterface> currentScene = nullptr;
static SDL_Window *window = nullptr;
static SDL_Renderer *globalRenderer = nullptr;

class VideoMode
{
  public:
    VideoMode(SceneType firstScene);
    ~VideoMode();
    bool Update();

  private:
    bool isRunning = true;
};
}; // namespace si