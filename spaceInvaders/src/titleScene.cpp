#include "titleScene.hpp"

si::TitleScene::TitleScene()
{
    tson::Tileson t;
    std::unique_ptr<tson::Map> map = t.parse("media/maps/title_screen.tmj");
    for (auto &layer : map->getLayers())
    {
        std::string layerName = layer.getName();
        if (layerName == "ui")
        {
            createUILayer(layer);
        }
        else if (layerName == "background")
        {
            createBackgroundLayer(layer);
        }
        else
        {
            LOG_FATAL("unhandled layer: %s\n", layerName.c_str());
        }
    }
}

bool si::TitleScene::Update(float deltaTime, SDL_Event *event)
{
    while (SDL_PollEvent(event))
    {
        if (event->type == SDL_QUIT)
        {
            return false;
        }
#ifdef SI_Debug
        if (event->type == SDL_KEYUP)
        {
            if (event->key.keysym.sym == SDLK_0)
            {
                std::string gameplayScene = "GAMEPLAY_SCENE";
                EventHandler::getInstance().emit("CHANGE_SCENE", (void *)gameplayScene.c_str());
            }
            if (event->key.keysym.sym == SDLK_ESCAPE)
            {
                return false;
            }
        }
#endif
    }

    return true;
}

void si::TitleScene::Render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void si::TitleScene::createBackgroundLayer(tson::Layer &layer)
{
    for (int y = 0; y < layer.getSize().y; ++y)
    {
        for (int x = 0; x < layer.getSize().x; ++x)
        {
            // Get the tile ID at this position
            tson::Tile *tile = layer.getTileData(x, y);
            if (tile != nullptr)
            {
                std::cout << "Tile at (" << x << "," << y << "): " << tile->getId() << std::endl;
                // TODO: create background tile object
                // append to a list
            }
        }
    }
}

void si::TitleScene::createUILayer(tson::Layer &layer)
{
    for (auto &object : layer.getObjects())
    {
        // Print object properties
        std::cout << "Object Name: " << object.getName() << std::endl;
        std::cout << "Object Type: " << object.getType() << std::endl;
        std::cout << "Position: (" << object.getPosition().x << ", " << object.getPosition().y << ")" << std::endl;
        std::cout << "Size: (" << object.getSize().x << ", " << object.getSize().y << ")" << std::endl;
        // TODO: create UI objects
   }
}
