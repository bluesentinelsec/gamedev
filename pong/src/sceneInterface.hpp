#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include <SFML/Window.hpp>

namespace game
{
class SceneInterface {
  public:
    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~SceneInterface() = default;

    /**
     * @brief Initialize the scene, load assets, set up initial state.
     * @return True if initialization was successful, false otherwise.
     */
    virtual bool Init() = 0;

    /**
     * @brief Handle events like key presses, mouse clicks, etc.
     * @param event The SFML event to handle.
     */
    virtual void HandleEvent(const sf::Event& event) = 0;

    /**
     * @brief Update the game logic, called every frame.
     * @param deltaTime Time elapsed since last update in seconds.
     */
    virtual bool Update(float deltaTime) = 0;

    /**
     * @brief Render the scene, called after Update.
     * @param window SFML window to use for rendering.
     */
    virtual void Render(std::shared_ptr<sf::RenderWindow> window) = 0;
};

}