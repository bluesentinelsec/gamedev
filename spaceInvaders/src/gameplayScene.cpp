
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

#ifdef SI_Debug
        if (event->type == SDL_KEYUP)
        {
            if (event->key.keysym.sym == SDLK_0)
            {
                std::string titleScene = "TITLE_SCENE";
                EventHandler::getInstance().emit("CHANGE_SCENE", (void *)titleScene.c_str());
            }
            if (event->key.keysym.sym == SDLK_ESCAPE)
            {
                return false;
            }
        }
#endif
    }
    LOG_INFO("Delta time: %f\n", deltaTime);
    return true;
}

void si::GameScene::Render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 100, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
