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
    isRunning = handleInput(deltaTime, event);

    if (!isPaused)
    {
        // update Player
        // update CPU
        // update ball
        // update Player score
        // update cpu score
    }

    // TODO - make the win/lose screen its own scene
    return isRunning;
}

bool game::GameplayScene::handleInput(float deltaTime, const sf::Event &event)
{
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
    {
        return false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        auto pos = player.rect.getPosition();
        player.rect.setPosition(pos.x, pos.y - 1 * player.speed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        auto pos = player.rect.getPosition();
        player.rect.setPosition(pos.x, pos.y + 1 * player.speed * deltaTime);
    }
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter)
    {
        isPaused = !isPaused;
        // TODO: play a sound
        // TODO: show a flashing message that says "PAUSED"
    }
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Num1)
    {
        char *winScene = "WIN_SCENE";
        EventHandler::getInstance().emit("CHANGE_SCENE", (void *)(winScene));
    }
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Num2)
    {
        char *scene = "LOSE_SCENE";
        EventHandler::getInstance().emit("CHANGE_SCENE", (void *)(scene));
    }

    return true;
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

    window->display();
}
