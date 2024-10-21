#include "titleScene.hpp"

si::TitleScene::TitleScene(SDL_Renderer *renderer)
{
    aRenderer = renderer;
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

    for (const auto &eachTile : BackgroundTiles)
    {
        eachTile->Render(renderer);
    }
    labelTitle.draw();
    labelStart.draw();
    labelExit.draw();

    SDL_RenderPresent(renderer);
}

void si::TitleScene::createBackgroundLayer(tson::Layer &layer)
{
    const auto &tileData = layer.getTileData();
    for (const auto &[position, tile] : tileData)
    {
        int x, y;
        std::tie(x, y) = position;
        if (tile && tile->getId() != 0)
        {
            auto aBackgroundTile = std::make_shared<BackgroundTile>(x * 40, y * 40, aRenderer);
            BackgroundTiles.push_back(aBackgroundTile);
        }
    }
}

void si::TitleScene::createUILayer(tson::Layer &layer)
{
    for (auto &object : layer.getObjects())
    {
        const std::string &objName = object.getName();
        if (objName == "label_title")
        {
            auto pos = object.getPosition();
            SDL_Color color = {.r = 35, .g = 55, .b = 25, .a = 255};
            labelTitle.init(pos.x, pos.y, "media/font/space_invaders.ttf", 144, color, "SPACE INVADERS", aRenderer);
        }
        else if (objName == "label_start")
        {
            auto pos = object.getPosition();
            SDL_Color color = {.r = 35, .g = 55, .b = 25, .a = 255};
            labelStart.init(pos.x, pos.y, "media/font/space_invaders.ttf", 72, color, "START", aRenderer);
        }
        else if (objName == "label_exit")
        {
            auto pos = object.getPosition();
            SDL_Color color = {.r = 35, .g = 55, .b = 25, .a = 255};
            labelExit.init(pos.x, pos.y, "media/font/space_invaders.ttf", 72, color, "EXIT", aRenderer);
        }
        else if (objName == "cursor")
        {
            // TODO: create object
        }
        else
        {
            LOG_FATAL("unhandled object: %s\n", objName.c_str());
        }
    }
}
