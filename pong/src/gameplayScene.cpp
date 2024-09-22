#include "gameplayScene.hpp"

game::GameplayScene::GameplayScene()
{
    playerScoreUI.SetPosition(32, 2);
    playerScoreUI.SetText(std::to_string(pScore));

    opponentScoreUI.SetPosition((160 - 32 - 8), 2);
    opponentScoreUI.SetText(std::to_string(opScore));
}

bool game::GameplayScene::Update(float deltaTime, const sf::Event &event)
{
    bool isRunning = true;
    isRunning = handleInput(deltaTime, event);

    checkIfScoreOccured();
    changeSceneOnVictory();

    if (!isBallActive)
    {
        spawnBall();
    }
    moveBall(deltaTime);
    handleCollisions();
    moveCPU(deltaTime);

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

    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Num1)
    {
        std::string winScene = "WIN_SCENE";
        EventHandler::getInstance().emit("CHANGE_SCENE", (void *)(winScene.c_str()));
    }
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Num2)
    {
        std::string scene = "LOSE_SCENE";
        EventHandler::getInstance().emit("CHANGE_SCENE", (void *)(scene.c_str()));
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
    window->draw(playerScoreUI.text);
    window->draw(opponentScoreUI.text);

    window->display();
}
void game::GameplayScene::changeSceneOnVictory()
{
    if (pScore >= scoreToWin)
    {
        std::string winScene = "WIN_SCENE";
        EventHandler::getInstance().emit("CHANGE_SCENE", (void *)(winScene.c_str()));
    }

    if (opScore >= scoreToWin)
    {
        std::string scene = "LOSE_SCENE";
        EventHandler::getInstance().emit("CHANGE_SCENE", (void *)(scene.c_str()));
    }
}
void game::GameplayScene::checkIfScoreOccured()
{
    auto position = ball.ball.getPosition();
    if (position.x < -32)
    {
        opScore += 1;
        opponentScoreUI.SetText(std::to_string(opScore));
        isBallActive = false;
    }
    if (position.x >= 160 + 32)
    {
        pScore += 1;
        playerScoreUI.SetText(std::to_string(pScore));
        isBallActive = false;
    }
}

void game::GameplayScene::spawnBall()
{
    ball.ball.setPosition(ball.ballX, ball.ballY);
    ball.angle = 0.0;
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_real_distribution<> dis(0.0, 2 * M_PI);
    ball.angle = dis(gen);
    if (std::abs(std::cos(ball.angle)) < 0.2)
    {
        ball.angle += 0.3;
    }
    isBallActive = true;
}

void game::GameplayScene::moveBall(float deltaTime)
{
    ball.velocity.x = ball.ballSpeed * std::cos(ball.angle) * deltaTime;
    ball.velocity.y = ball.ballSpeed * std::sin(ball.angle) * deltaTime;
    ball.ball.move(ball.velocity.x, ball.velocity.y);
}

void game::GameplayScene::handleCollisions()
{
    sf::Vector2f position = ball.ball.getPosition();
    float ballRadius = ball.ball.getRadius();

    // Random number generator for angle adjustment
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> angleAdjustment(-0.1, 0.1); // Small adjustment range

    // Check if the ball hits the top of the screen
    if (position.y - ballRadius < 0) // Ball hits the top
    {
        // Reverse the Y angle
        ball.angle = -ball.angle;

        // Correct any overshoot and move the ball by the remaining distance
        float overshoot = ballRadius - position.y;
        ball.ball.move(0, 2 * overshoot); // Bounce back by the overshoot amount
    }
    // Check if the ball hits the bottom of the screen
    else if (position.y + ballRadius > 144) // Ball hits the bottom
    {
        // Reverse the Y angle
        ball.angle = -ball.angle;

        // Correct any overshoot and move the ball by the remaining distance
        float overshoot = (position.y + ballRadius) - 144;
        ball.ball.move(0, -2 * overshoot); // Bounce back by the overshoot amount
    }

    // Check for collisions with the player's paddle
    if (ball.ball.getGlobalBounds().intersects(player.rect.getGlobalBounds()))
    {
        // Reflect horizontally and add a small random angle adjustment
        ball.angle = M_PI - ball.angle + angleAdjustment(gen);

        // Adjust ball's position to prevent sticking to the paddle
        float overshoot = (player.rect.getPosition().x + player.width) - position.x;
        ball.ball.move(2 * overshoot, 0);
    }

    // Check for collisions with the opponent's paddle
    if (ball.ball.getGlobalBounds().intersects(opponent.rect.getGlobalBounds()))
    {
        // Reflect horizontally and add a small random angle adjustment
        ball.angle = M_PI - ball.angle + angleAdjustment(gen);

        // Adjust ball's position to prevent sticking to the paddle
        float overshoot = (position.x + ballRadius) - opponent.rect.getPosition().x;
        ball.ball.move(-2 * overshoot, 0);
    }
}

void game::GameplayScene::moveCPU(float deltaTime)
{
    auto ballPOS = ball.ball.getPosition();
    auto opponentPOS = opponent.rect.getPosition();

    // Random number generator for CPU imperfection
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> randomChance(0.0, 1.0);
    float chance = randomChance(gen);

    // Move opponent towards the ball's vertical position
    if (chance > 0.1) // 90% chance the CPU plays well
    {
        if (ballPOS.y < opponentPOS.y)
        {
            opponent.rect.setPosition(opponentPOS.x, opponentPOS.y - opponent.speed * deltaTime);
        }
        else if (ballPOS.y > opponentPOS.y + opponent.height)
        {
            opponent.rect.setPosition(opponentPOS.x, opponentPOS.y + opponent.speed * deltaTime);
        }
    }
    else // 10% chance the CPU plays poorly
    {
        // Simulate a bad move by moving slowly or not reacting
        if (chance > 0.05)
        {
            if (ballPOS.y < opponentPOS.y)
            {
                opponent.rect.setPosition(opponentPOS.x,
                                          opponentPOS.y - (opponent.speed * deltaTime * 0.5)); // Slow movement
            }
            else if (ballPOS.y > opponentPOS.y + opponent.height)
            {
                opponent.rect.setPosition(opponentPOS.x,
                                          opponentPOS.y + (opponent.speed * deltaTime * 0.5)); // Slow movement
            }
        }
        else
        {
            // Do nothing to simulate a complete miss
        }
    }

    // Ensure opponent's paddle doesn't go off the screen
    if (opponent.rect.getPosition().y < 0)
    {
        opponent.rect.setPosition(opponentPOS.x, 0);
    }
    else if (opponent.rect.getPosition().y + opponent.height > 144)
    {
        opponent.rect.setPosition(opponentPOS.x, 144 - opponent.height);
    }
}
