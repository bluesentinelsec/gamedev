#include "backgroundTile.hpp"

si::BackgroundTile::BackgroundTile(int x, int y, SDL_Renderer *renderer)
{
    xPos = x;
    yPos = y;
    surf.set(spritePath);
    tex.set(renderer, surf);
}

si::BackgroundTile::~BackgroundTile()
{
}

bool si::BackgroundTile::Update(float deltaTime, SDL_Event *event)
{
    return true;
}

void si::BackgroundTile::Render(SDL_Renderer *renderer)
{
    auto theTexture = tex.get();
    SDL_Rect dst = {.x = xPos, .y = yPos, .w = 40, .h = 40};
    SDL_Rect src = {.x = 0, .y = 0, .w = 40, .h = 40};
    SDL_RenderCopy(renderer, theTexture, &src, &dst);
}
