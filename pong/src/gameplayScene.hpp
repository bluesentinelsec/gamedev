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

const int screenWidth = 160;
const int screenHeight = 144;

class GameplayScene : public SceneInterface
{
  public:
    GameplayScene();
    ~GameplayScene() override = default;

    bool Init() override;
    bool Update(float deltaTime, const sf::Event &event) override;
    void Render(std::shared_ptr<sf::RenderWindow> window) override;

  private:
    sf::RectangleShape player;
    int playerWidth = 2;
    int playerHeight = 16;
    int playerX = playerWidth;
    int playerY = (screenHeight - playerHeight) / 2;
    int playerSpeed = 10;
    sf::Color playerColor{15, 56, 15, 255};

    sf::RectangleShape opponent;
    int oppW = 2;
    int oppH = 16;
    int oppX = screenWidth - oppW * 2;
    int oppY = (screenHeight - oppH) / 2;
    int oppSpeed = 10;
    sf::Color oppColor{15, 56, 15, 255};

    sf::CircleShape ball;
    int ballX = 0;
    int ballY = 0;
    int ballRadius = 2;
    int ballSpeed = 10;
    sf::Color ballColor{15, 56, 15, 255};

    // UI elements
    sf::Font uiFont;
    sf::Text playerScoreUI;
    sf::Color fontColor{15, 56, 15, 255};

    sf::Text oppScoreUI;
};

} // namespace game
