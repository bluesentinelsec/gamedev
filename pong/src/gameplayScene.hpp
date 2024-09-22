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
#include <cstdlib>
#include <random>

namespace game
{

const int screenWidth = 160;
const int screenHeight = 144;

class GameplayScene : public SceneInterface
{
  public:
    GameplayScene();
    ~GameplayScene() override = default;

    bool Update(float deltaTime, const sf::Event &event) override;
    void Render(std::shared_ptr<sf::RenderWindow> window) override;

  private:
    bool handleInput(float deltaTime, const sf::Event &event);
    void changeSceneOnVictory();
    void checkIfScoreOccured();

    bool isPaused = false;

    // actors
    Player player;
    Opponent opponent;
    void moveCPU(float deltaTime);

    Ball ball;
    bool isBallActive = true;
    void spawnBall();
    void moveBall(float deltaTime);
    void handleCollisions();

    Score playerScoreUI;
    int pScore = 0;

    Score opponentScoreUI;
    int opScore = 0;

    const int scoreToWin = 3;

    // win & lose screen elements
    bool showYouWin = false;
    bool showYouLose = false;
};

} // namespace game
