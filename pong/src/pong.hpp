#pragma once

#include "logger.hpp"
#include "sceneFactory.hpp"
#include "sceneInterface.hpp"

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/VideoMode.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

namespace game
{

class Pong
{
  public:
    Pong();
    ~Pong();

    void start();
    bool update();
    void exit();
    int ScreenWidth = 160;
    int ScreenHeight = 144;

  private:
    sf::VideoMode videoMode;
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<SceneInterface> currentScene = nullptr;
    sf::Clock clock;
};

} // namespace game
