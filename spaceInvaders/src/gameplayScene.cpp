
#include "gameplayScene.hpp"

si::GameScene::GameScene()
{
}

bool si::GameScene::Update(float deltaTime, SDL_Event *event)
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

void si::GameScene::Render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 100, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
