#include "gameplayScene.hpp"

game::GameplayScene::GameplayScene()
{
    playerScore.SetPosition(32, 2);
    playerScore.SetText("0");

    opponentScore.SetPosition((160 - 32 - 8), 2);
    opponentScore.SetText("0");
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
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Num1)
    {
        showYouWin = !showYouWin;
    }

    if (!isPaused)
    {
        // update Player
        // update CPU
        // update ball
        // update Player score
        // update cpu score
    }

    if (showYouWin)
    {
        winScreen.Update(deltaTime, event);
    }
    if (showYouLose)
    {
        loseScreen.Update(deltaTime, event);
    }

    return isRunning;
}

void game::GameplayScene::Render(std::shared_ptr<sf::RenderWindow> window)
{
    window->clear(sf::Color(155, 188, 15, 255));
    // draw actors
    window->draw(player.rect);
    window->draw(opponent.rect);
    window->draw(ball.ball);
    window->draw(playerScore.text);
    window->draw(opponentScore.text);

    if (showYouWin)
    {
        winScreen.Render(window);
    }
    if (showYouLose)
    {
        loseScreen.Render(window);
    }

    window->display();
}
