#pragma once

#include "eventManager.hpp"
#include "logger.hpp"
#include "sceneInterface.hpp"
#include <SDL.h>
#include <memory>

namespace si
{

class GameScene : public SceneInterface
{
  public:
    GameScene();
    ~GameScene() override = default;

    bool Update(float deltaTime, SDL_Event *event) override;

    void Render(SDL_Renderer *renderer) override;

  private:
};

} // namespace si
