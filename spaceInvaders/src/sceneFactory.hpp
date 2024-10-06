#pragma once

#include "logger.hpp"
#include "sceneInterface.hpp"
#include <memory>

// [!] Include concrete scene implementations here
#include "titleScene.hpp"

namespace si
{

enum class SceneType
{
    TitleScene,
    GameplayScene,
    WinScene,
    LoseScene,
    // [!] add additional scene types here
};

class SceneFactory
{
  public:
    static std::shared_ptr<SceneInterface> CreateScene(SceneType type)
    {
        if (type == SceneType::TitleScene)
        {
            return std::make_shared<TitleScene>();
        }
        else if (type == SceneType::GameplayScene)
        {
            LOG_FATAL("scene not implemented");
        }
        else if (type == SceneType::WinScene)
        {
            LOG_FATAL("scene not implemented");
        }
        else if (type == SceneType::LoseScene)
        {
            LOG_FATAL("scene not implemented");
        }
        else
        {
            LOG_FATAL("invalid type provided: %d\n", type);
            return nullptr;
        }
        return nullptr;
    };
};

} // namespace si
