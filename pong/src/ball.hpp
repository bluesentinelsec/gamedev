#pragma once

#include "SFML/Graphics/CircleShape.hpp"

namespace game
{

class Ball
{
  public:
    Ball();
    sf::CircleShape ball;
    int ballX = 0;
    int ballY = 0;
    int ballRadius = 2;
    int ballSpeed = 100;
    sf::Vector2f velocity;
    float angle;
    sf::Color ballColor{15, 56, 15, 255};
};

} // namespace game
