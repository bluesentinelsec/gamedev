#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include <SFML/Window.hpp>
#include "customEventManager.hpp"

namespace game
{
class SceneInterface {
  public:
    virtual ~SceneInterface() = default;

    virtual bool Init() = 0;

    virtual bool Update(float deltaTime, const sf::Event& event) = 0;

    virtual void Render(std::shared_ptr<sf::RenderWindow> window) = 0;
};
}