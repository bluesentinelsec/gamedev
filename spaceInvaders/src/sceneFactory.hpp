#pragma once

#include "logger.hpp"
#include "sceneInterface.hpp"
#include <memory>

// [!] Include concrete scene implementations here
#include "gameplayScene.hpp"
#include "titleScene.hpp"

namespace si
{

enum class SceneType
{
    TitleScene,
    GameplayScene,
    // [!] add additional scene types here
};

class SceneFactory
{
  public:
    static std::shared_ptr<SceneInterface> CreateScene(SceneType type, SDL_Renderer *renderer)
    {
        if (type == SceneType::TitleScene)
        {
            return std::make_shared<TitleScene>(renderer);
        }
        else if (type == SceneType::GameplayScene)
        {
            return std::make_shared<GameScene>();
        }
        else
        {
            LOG_FATAL("invalid type provided: %d\n", type);
            return nullptr;
        }
    };
};

} // namespace si
