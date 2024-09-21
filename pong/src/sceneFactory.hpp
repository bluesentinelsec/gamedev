#pragma once

#include "logger.hpp"
#include "sceneInterface.hpp"
#include <memory>

// [!] Include concrete scene implementations here
#include "WinLoseScene.hpp"
#include "gameplayScene.hpp"
#include "titleScene.hpp"

namespace game
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
            return std::make_shared<GameplayScene>();
        }
        else if (type == SceneType::WinScene)
        {
            auto s = std::make_shared<WinLoseScene>();
            s->winLoseText.setString("YOU WIN!");
            return s;
        }
        else if (type == SceneType::LoseScene)
        {
            auto s = std::make_shared<WinLoseScene>();
            s->winLoseText.setString("YOU LOSE!");
            return s;
        }
        else
        {
            LOG_FATAL("invalid type provided: %d\n", type);
            return nullptr;
        }
    }
};

} // namespace game
