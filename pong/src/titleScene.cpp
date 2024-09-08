#include "titleScene.hpp"

game::TitleScene::TitleScene()
{
    LOG_DEBUG("Title scene constructor");
    // create background
    // create title text
    auto fontPath = pathutils::WithResourcePath("media/font/GameBoyFont.ttf");
    if (!titleFont.loadFromFile(fontPath.c_str()))
    {
        LOG_FATAL("unable to load media file: %s\n", fontPath.c_str());
    };
    auto fontColor = sf::Color(15, 56, 15, 255);
    titleFont.setSmooth(false);
    titleText.setFont(titleFont);
    titleText.setString("PONG");
    titleText.setCharacterSize(16);
    titleText.setFillColor(fontColor);
    titleText.setPosition(29, 31);

    // create start text
    // create exit text
    // create cursor object
}

bool game::TitleScene::Init()
{
    LOG_DEBUG("Initializing title scene");
    return true;
}

void game::TitleScene::HandleEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
    {
        LOG_DEBUG("ESCAPE PRESSED!");
        isRunning = false;
    }
}

bool game::TitleScene::Update(float deltaTime)
{
    // update actors
    return isRunning;
}

void game::TitleScene::Render(std::shared_ptr<sf::RenderWindow> window)
{
    window->clear(sf::Color(155, 188, 15, 255));
    // draw actors
    window->draw(titleText);
    window->display();
}
