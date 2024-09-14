#include "gameplayScene.hpp"

game::GameplayScene::GameplayScene()
{
    // initialize player
    player.setSize(sf::Vector2f(playerWidth, playerHeight));
    player.setPosition(playerX, playerY);
    player.setFillColor(playerColor);
    player.setOutlineColor(playerColor);

    // initialize opponent
    opponent.setSize(sf::Vector2f(oppW, oppH));
    opponent.setPosition(oppX, oppY);
    opponent.setFillColor(oppColor);
    opponent.setOutlineColor(oppColor);

    // initialize ball
    ball.setRadius(ballRadius);
    ballX = screenWidth / 2 - ballRadius;
    ballY = screenHeight / 2 - ballRadius;
    ball.setPosition(ballX, ballY);
    ball.setFillColor(ballColor);
    ball.setOutlineColor(ballColor);

    // initialize font for UI
    auto fontPath = pathutils::WithResourcePath("media/font/GameBoyFont.ttf");
    if (!uiFont.loadFromFile(fontPath.c_str()))
    {
        LOG_FATAL("unable to load media file: %s\n", fontPath.c_str());
    };
    uiFont.setSmooth(false);

    // init score objects
    playerScoreUI.setFont(uiFont);
    playerScoreUI.setOutlineColor(fontColor);
    playerScoreUI.setFillColor(fontColor);
    playerScoreUI.setPosition(32, 2);
    playerScoreUI.setCharacterSize(16);
    playerScoreUI.setString("0");

    oppScoreUI.setFont(uiFont);
    oppScoreUI.setOutlineColor(fontColor);
    oppScoreUI.setFillColor(fontColor);
    oppScoreUI.setPosition(screenWidth - 32 - 8, 2);
    oppScoreUI.setCharacterSize(16);
    oppScoreUI.setString("0");
}

bool game::GameplayScene::Init()
{
    return true;
}

bool game::GameplayScene::Update(float deltaTime, const sf::Event &event)
{
    bool isRunning = true;
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
    {
        LOG_DEBUG("ESCAPE PRESSED!");
        isRunning = false;
    }

    return isRunning;
}

void game::GameplayScene::Render(std::shared_ptr<sf::RenderWindow> window)
{
    window->clear(sf::Color(155, 188, 15, 255));
    // draw actors
    window->draw(player);
    window->draw(opponent);
    window->draw(ball);
    window->draw(playerScoreUI);
    window->draw(oppScoreUI);
    window->display();
}
