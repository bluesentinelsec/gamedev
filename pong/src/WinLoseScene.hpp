#pragma once

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "logger.hpp"
#include "pathutils.hpp"
#include "sceneInterface.hpp"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

namespace game
{
class WinLoseScene : public SceneInterface
{
  public:
    WinLoseScene();
    bool Update(float deltaTime, const sf::Event &event) override;
    void Render(std::shared_ptr<sf::RenderWindow> window) override;
    sf::Text winLoseText;

  private:
    sf::Font uiFont;
    int titleX = 23;
    int titleY = 29;

    sf::Text startText;
    int startX = 41;
    int startY = 77;

    sf::Text exitText;
    int exitX = 63;
    int exitY = 95;

    sf::Texture cursorTexture;
    sf::Sprite cursorSprite;
    int cursorStartX = 30;
    int cursorStartY = 77;
    int cursorExitX = 52;
    int cursorExitY = 96;
};

} // namespace game
