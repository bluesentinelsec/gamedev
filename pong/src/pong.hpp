#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/VideoMode.hpp"
#include <SFML/Graphics.hpp>

namespace game
{

class Pong
{
  public:
    Pong();
    ~Pong();

    void start();
    bool update();
    void render();
    void exit();

  private:
    sf::VideoMode videoMode;
    sf::RenderWindow window;
};

} // namespace game
