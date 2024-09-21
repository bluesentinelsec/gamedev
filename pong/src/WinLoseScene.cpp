//
// Created by Michael Long on 9/15/24.
//

#include "WinLoseScene.hpp"

game::WinLoseScene::WinLoseScene()
{
    // create UI font
    auto fontPath = pathutils::WithResourcePath("media/font/GameBoyFont.ttf");
    if (!uiFont.loadFromFile(fontPath.c_str()))
    {
        LOG_FATAL("unable to load media file: %s\n", fontPath.c_str());
    };
    auto fontColor = sf::Color(15, 56, 15, 255);
    uiFont.setSmooth(false);

    // create title text
    winLoseText.setFont(uiFont);
    winLoseText.setString("YOU WIN!");
    winLoseText.setCharacterSize(16);
    winLoseText.setFillColor(fontColor);
    winLoseText.setPosition(titleX, titleY);

    // create start text
    startText.setFont(uiFont);
    startText.setString("PLAY AGAIN");
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

bool game::WinLoseScene::Init()
{
    return false;
}
bool game::WinLoseScene::Update(float deltaTime, const sf::Event &event)
{
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
    {
        return false;
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
            char *gameplayScene = "GAMEPLAY_SCENE";
            EventHandler::getInstance().emit("CHANGE_SCENE", (void *)(gameplayScene));
        }
        else
        {
            char *gameplayScene = "TITLE_SCENE";
            EventHandler::getInstance().emit("CHANGE_SCENE", (void *)(gameplayScene));
        }
    }

    return true;
}
void game::WinLoseScene::Render(std::shared_ptr<sf::RenderWindow> window)
{
    window->clear(sf::Color(155, 188, 15, 255));
    window->draw(winLoseText);
    window->draw(startText);
    window->draw(exitText);
    window->draw(cursorSprite);
    window->display();
}
