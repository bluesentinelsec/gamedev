#pragma once

#include "eventManager.hpp"
#include "sceneInterface.hpp"
#include <SDL.h>
#include <memory>

namespace si
{

class TitleScene : public SceneInterface
{
  public:
    TitleScene();
    ~TitleScene() override = default;

    bool Update(float deltaTime, SDL_Event *event) override;

    void Render(SDL_Renderer *renderer) override;

  private:
};

} // namespace si
