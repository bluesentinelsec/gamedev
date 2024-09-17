//
// Created by Michael Long on 9/16/24.
//

#include "Player.hpp"

namespace game
{
Player::Player()
{
    rect.setSize(sf::Vector2f(width, height));
    rect.setPosition(xPos, yPos);
    rect.setFillColor(color);
    rect.setOutlineColor(color);
}
} // namespace game