#include "titleScene.hpp"

game::TitleScene::TitleScene()
{
    LOG_DEBUG("Title scene constructor");

    // create UI font
    auto fontPath = pathutils::WithResourcePath("media/font/GameBoyFont.ttf");
    if (!uiFont.loadFromFile(fontPath.c_str()))
    {
        LOG_FATAL("unable to load media file: %s\n", fontPath.c_str());
    };
    auto fontColor = sf::Color(15, 56, 15, 255);
    uiFont.setSmooth(false);

    // create title text
    titleText.setFont(uiFont);
    titleText.setString("PONG");
    titleText.setCharacterSize(16);
    titleText.setFillColor(fontColor);
    titleText.setPosition(titleX, titleY);

    // create start text
    startText.setFont(uiFont);
    startText.setString("START");
    startText.setCharacterSize(8);
    startText.setFillColor(fontColor);
    startText.setPosition(startX, startY);

    // create exit text
    exitText.setFont(uiFont);
    exitText.setString("EXIT");
    exitText.setCharacterSize(8);
    exitText.setFillColor(fontColor);
    exitText.setPosition(exitX, exitY);

    // create cursor object
    auto cursorTexturePath = pathutils::WithResourcePath("media/images/cursor_8x8.png");
    if (!cursorTexture.loadFromFile(cursorTexturePath))
    {
        LOG_FATAL("unable to load media file: %s\n", cursorTexturePath.c_str());
    }
    cursorTexture.setSmooth(false);
    cursorSprite.setTexture(cursorTexture);
    cursorSprite.setPosition(cursorStartX, cursorStartY);
}

bool game::TitleScene::Init()
{
    LOG_DEBUG("Initializing title scene");
    return true;
}

bool game::TitleScene::Update(float deltaTime, const sf::Event &event)
{
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
    {
        LOG_DEBUG("ESCAPE PRESSED!");
        isRunning = false;
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
    {
        xPos -= 1 * objSpeed * deltaTime;
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
    {
        xPos += 1 * objSpeed * deltaTime;
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
    {
        yPos -= 1 * objSpeed * deltaTime;
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
    {
        yPos += 1 * objSpeed * deltaTime;
    }
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down)
    {
        auto pos = cursorSprite.getPosition();
        if (pos.x == cursorStartX && pos.y == cursorStartY)
        {
            cursorSprite.setPosition(cursorExitX, cursorExitY);
        }
        else
        {
            cursorSprite.setPosition(cursorStartX, cursorStartY);
        }
    }
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)
    {
        auto pos = cursorSprite.getPosition();
        if (pos.x == cursorStartX && pos.y == cursorStartY)
        {
            cursorSprite.setPosition(cursorExitX, cursorExitY);
        }
        else
        {
            cursorSprite.setPosition(cursorStartX, cursorStartY);
        }
    }
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter)
    {
        auto pos = cursorSprite.getPosition();
        if (pos.x == cursorStartX && pos.y == cursorStartY)
        {
            LOG_INFO("CREATE GAME SCENE");
            char *gameplayScene = "GAMEPLAY_SCENE";
            EventHandler::getInstance().emit("CHANGE_SCENE", (void *)(gameplayScene));
        }
        else
        {
            return false;
        }
    }

    return isRunning;
}

void game::TitleScene::Render(std::shared_ptr<sf::RenderWindow> window)
{
    window->clear(sf::Color(155, 188, 15, 255));

    // draw actors
    window->draw(titleText);
    window->draw(startText);
    window->draw(exitText);
    window->draw(cursorSprite);

    window->display();
}
