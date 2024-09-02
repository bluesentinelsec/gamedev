#include "pong.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/WindowStyle.hpp"
#include <memory>
#include <iostream>

namespace game
{

Pong::Pong()
{
    videoMode = sf::VideoMode(sf::VideoMode::getDesktopMode());
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0; // disable anti-aliasing
    window = std::make_unique<sf::RenderWindow>(videoMode, "Pong", sf::Style::Default | sf::Style::Resize, settings);
    sf::View logicalView(sf::FloatRect(0, 0, 426, 240));
    window->setView(logicalView);
    window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(60);
}

Pong::~Pong()
{
}

void Pong::start()
{
}

bool Pong::update()
{
    while (window->isOpen())
    {
        sf::Event event{};
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                return false;
            }

            if (event.type == sf::Event::Resized)
            {
                // Adjust the view to maintain the logical resolution
                sf::FloatRect visibleArea(0, 0, 426, 240);
                window->setView(sf::View(visibleArea));
            }

            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
            {
                return false;
            }
        }
        render();
    }
    return true;
}

void Pong::render()
{
    window->clear(sf::Color::Green);

    sf::RectangleShape rectangle(sf::Vector2f(100.f, 100.f));
    rectangle.setPosition(10.f, 20.f);
    rectangle.setFillColor(sf::Color::Red);
    window->draw(rectangle);

    window->display();
}

void Pong::exit()
{
    window->close();
}

} // namespace game
