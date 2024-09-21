#pragma once

#include "Opponent.hpp"
#include "Player.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "ball.hpp"
#include "logger.hpp"
#include "pathutils.hpp"
#include "sceneInterface.hpp"
#include "score.hpp"

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
    bool handleInput(float deltaTime, const sf::Event &event);

    bool isPaused = false;

    // actors
    Player player;
    Opponent opponent;
    Ball ball;
    Score playerScore;
    Score opponentScore;

    // win & lose screen elements
    bool showYouWin = false;
    bool showYouLose = false;
};

} // namespace game
