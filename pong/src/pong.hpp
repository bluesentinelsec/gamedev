#pragma once

#include "logger.hpp"

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
    int ScreenHeight = 320;
    int ScreenWidth = 180;

  private:
    void render();
    sf::VideoMode videoMode;
    std::unique_ptr<sf::RenderWindow> window;
};

} // namespace game
