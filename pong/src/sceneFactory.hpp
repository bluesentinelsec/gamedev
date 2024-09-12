#pragma once

#include "sceneInterface.hpp"
#include "logger.hpp"
#include <memory>

// [!] Include concrete scene implementations here
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
        // [!] Add cases for other scenes when implemented
        default:
            LOG_FATAL("invalid type provided: %d\n", type);
            return nullptr;
        }
    }
};

} // namespace game
