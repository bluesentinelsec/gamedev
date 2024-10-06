#pragma once

#include "eventManager.hpp"
#include <SDL.h>

namespace si
{
class SceneInterface
{
  public:
    virtual ~SceneInterface() = default;

    virtual bool Update(float deltaTime, SDL_Event *event) = 0;

    virtual void Render(SDL_Renderer *renderer) = 0;
};
} // namespace si
