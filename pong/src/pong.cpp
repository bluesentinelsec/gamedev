#include "pong.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/WindowStyle.hpp"

namespace game
{

Pong::Pong() : videoMode(800, 600), window(sf::VideoMode(videoMode), "Pong Game", sf::Style::Default)
{
    // Constructor implementation
}

Pong::~Pong()
{
    // Destructor implementation
}

void Pong::start()
{
}

bool Pong::update()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return false;
            }
        }
    }
    return true;
}

void Pong::render()
{
    window.clear();
    window.display();
}

void Pong::exit()
{
    // Exit the game
}

} // namespace game
