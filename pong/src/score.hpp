#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "logger.hpp"
#include "pathutils.hpp"

namespace game
{

class Score
{
  public:
    Score();
    sf::Font font;
    sf::Text text;
    sf::Color black{15, 56, 15, 255};
    void SetPosition(int x, int y);
    void SetText(std::string score);
};

} // namespace game