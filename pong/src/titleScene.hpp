#pragma once

#include "sceneInterface.hpp"
#include "logger.hpp"
#include "pathutils.hpp"

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

namespace game {

class TitleScene : public SceneInterface {
  public:
    TitleScene();
    ~TitleScene() override = default;

    // Initialize the scene by loading assets, setting up initial state
    bool Init() override;

    // Handle user input events
    void HandleEvent(const sf::Event& event) override;

    // Update game logic
    bool Update(float deltaTime) override;

    // Render the title scene
    void Render(std::shared_ptr<sf::RenderWindow> window) override;

  private:
    bool isRunning = true;

    sf::Font titleFont;
    sf::Text titleText;
    sf::Font startFont;
    sf::Text startText;
    sf::Font exitFont;
    sf::Text exitText;
};

}  // namespace game
