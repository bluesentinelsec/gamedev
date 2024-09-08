#include "pong.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/WindowStyle.hpp"
#include <memory>

namespace game
{

Pong::Pong()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0; // disable anti-aliasing

    LOG_DEBUG("initializing video mode and game window");
#ifdef Pong_Release
    videoMode = sf::VideoMode(sf::VideoMode::getFullscreenModes()[0]);
    window = std::make_shared<sf::RenderWindow>(videoMode, "Pong", sf::Style::Fullscreen, settings);
#else
    videoMode = sf::VideoMode(sf::VideoMode::getDesktopMode());
    window = std::make_shared<sf::RenderWindow>(videoMode, "Pong", sf::Style::Default | sf::Style::Resize, settings);
#endif
    sf::View logicalView(sf::FloatRect(0, 0, ScreenWidth, ScreenHeight));
    window->setView(logicalView);
    window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(60);
}

Pong::~Pong()
{
}

void Pong::start()
{
    LOG_DEBUG("starting game");
    currentScene = SceneFactory::CreateScene(SceneType::TitleScene);
}

bool Pong::update()
{
    bool isRunning = true;
    while (window->isOpen())
    {
        sf::Event event{};
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                isRunning = false;
            }
            else if (event.type == sf::Event::Resized)
            {
                // Adjust the view to maintain the logical resolution
                sf::FloatRect visibleArea(0, 0, ScreenWidth, ScreenHeight);
                window->setView(sf::View(visibleArea));
            }
            else
            {
                currentScene->HandleEvent(event);
            }
        }
        isRunning = currentScene->Update(0);
        currentScene->Render(window);

        if (!isRunning)
        {
            break;
        }
    }
    return isRunning;
}


void Pong::exit()
{
    LOG_DEBUG("exiting game");
    window->close();
}

} // namespace game
