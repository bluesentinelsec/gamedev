#include "pong.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/WindowStyle.hpp"
#include <memory>

namespace game
{
void onChangeScene(void *args);

Pong::Pong()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0; // disable anti-aliasing

    LOG_DEBUG("initializing video mode and game window");
    videoMode = sf::VideoMode(sf::VideoMode::getDesktopMode());
    window = std::make_shared<sf::RenderWindow>(videoMode, "Pong", sf::Style::Default | sf::Style::Resize, settings);
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
    EventHandler::getInstance().subscribe("CHANGE_SCENE", onChangeScene);
}

bool Pong::update()
{
    bool isRunning = true;
    while (window->isOpen())
    {
        sf::Time deltaTime = clock.restart();

        sf::Event event{};
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                isRunning = false;
            }
            if (event.type == sf::Event::Resized)
            {
                // Adjust the view to maintain the logical resolution
                sf::FloatRect visibleArea(0, 0, ScreenWidth, ScreenHeight);
                window->setView(sf::View(visibleArea));
            }
        }
        isRunning = currentScene->Update(deltaTime.asSeconds(), event);
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

void onChangeScene(void *args)
{
    std::string sceneToLoad = (char *)(args);
    if (sceneToLoad == "GAMEPLAY_SCENE")
    {
        currentScene = SceneFactory::CreateScene(SceneType::GameplayScene);
    }
    else if (sceneToLoad == "WIN_SCENE")
    {
        currentScene = SceneFactory::CreateScene(SceneType::WinScene);
    }
    else if (sceneToLoad == "TITLE_SCENE")
    {
        currentScene = SceneFactory::CreateScene(SceneType::TitleScene);
    }
    else if (sceneToLoad == "LOSE_SCENE")
    {
        currentScene = SceneFactory::CreateScene(SceneType::LoseScene);
    }

    else
    {
        LOG_FATAL("invalid scene: %s\n", sceneToLoad.c_str());
    }
}

} // namespace game
