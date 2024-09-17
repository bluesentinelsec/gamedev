#pragma once

#include "SFML/Graphics/RectangleShape.hpp"

namespace game
{

class Opponent
{
  public:
    Opponent();
    sf::RectangleShape rect;
    const int width = 2;
    const int height = 16;
    int xPos = 160 - (width * 2);
    int yPos = 64;
    int speed = 10;
    sf::Color color{15, 56, 15, 255};
};

} // namespace game
