#pragma once

#include "SFML/Graphics/RectangleShape.hpp"

namespace game
{

class Player
{
  public:
    Player();
    sf::RectangleShape rect;
    const int width = 2;
    const int height = 16;
    int xPos = width;
    int yPos = 64;
    int speed = 10;
    sf::Color color{15, 56, 15, 255};
    const int screenWidth = 160;
    const int screenHeight = 144;
};

} // namespace game
