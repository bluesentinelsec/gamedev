#pragma once

#include "backgroundTile.hpp"
#include "eventManager.hpp"
#include "font.hpp"
#include "logger.hpp"
#include "sceneInterface.hpp"

#include <SDL.h>
#include <memory>
#include <tileson.hpp>

namespace si
{

class TitleScene : public SceneInterface
{
  public:
    TitleScene(SDL_Renderer *renderer);
    ~TitleScene() override = default;

    bool Update(float deltaTime, SDL_Event *event) override;

    void Render(SDL_Renderer *renderer) override;

  private:
    void createBackgroundLayer(tson::Layer &);
    void createUILayer(tson::Layer &);
    std::vector<std::shared_ptr<BackgroundTile>> BackgroundTiles;
    SDL_Renderer *aRenderer;
    Font labelTitle;
    Font labelStart;
    Font labelExit;
};

} // namespace si
