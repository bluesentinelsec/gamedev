#pragma once

#include "logger.hpp"
#include "sceneInterface.hpp"
#include <memory>

// [!] Include concrete scene implementations here
#include "gameplayScene.hpp"
#include "titleScene.hpp"

namespace game
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
    static std::shared_ptr<SceneInterface> CreateScene(SceneType type)
    {
        switch (type)
        {
        case SceneType::TitleScene:
            return std::make_shared<TitleScene>();
        case SceneType::GameplayScene:
            return std::make_shared<GameplayScene>();
        default:
            LOG_FATAL("invalid type provided: %d\n", type);
            return nullptr;
        }
    }
};

} // namespace game
