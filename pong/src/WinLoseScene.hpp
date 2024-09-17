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
    bool Init() override;
    bool Update(float deltaTime, const sf::Event &event) override;
    void Render(std::shared_ptr<sf::RenderWindow> window) override;

  private:
    sf::Font uiFont;
    sf::Text titleText;
    int titleX = 51;
    int titleY = 33;

    sf::Text startText;
    int startX = 63;
    int startY = 77;

    sf::Text exitText;
    int exitX = 67;
    int exitY = 95;

    sf::Texture cursorTexture;
    sf::Sprite cursorSprite;
    int cursorStartX = 52;
    int cursorStartY = 77;
    int cursorExitX = 57;
    int cursorExitY = 96;
};

} // namespace game
