#include "titleScene.hpp"

si::TitleScene::TitleScene()
{
}

bool si::TitleScene::Update(float deltaTime, SDL_Event *event)
{
    while (SDL_PollEvent(event))
    {
        if (event->type == SDL_QUIT)
        {
            return false;
        }
    }
    return true;
}

void si::TitleScene::Render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
