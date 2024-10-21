#pragma once

#include "eventManager.hpp"
#include "sceneInterface.hpp"
#include "surface.hpp"
#include "texture.hpp"
#include <SDL.h>

namespace si
{

class BackgroundTile : public SceneInterface
{
  public:
    BackgroundTile(int x, int y, SDL_Renderer *renderer);
    ~BackgroundTile() override;
    bool Update(float deltaTime, SDL_Event *event) override;

    void Render(SDL_Renderer *renderer) override;

  private:
    int xPos = 0;
    int yPos = 0;
    std::string spritePath = "media/images/green_tile.png";
    sdlSurface surf;
    Texture tex;
};

} // namespace si
