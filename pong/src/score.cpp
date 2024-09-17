#include "score.hpp"

namespace game
{
Score::Score()
{
    // initialize font for UI
    auto fontPath = pathutils::WithResourcePath("media/font/GameBoyFont.ttf");
    if (!uiFont.loadFromFile(fontPath.c_str()))
    {
        LOG_FATAL("unable to load media file: %s\n", fontPath.c_str());
    };
    uiFont.setSmooth(false);

    // init score objects
    text.setFont(uiFont);
    text.setOutlineColor(fontColor);
    text.setFillColor(fontColor);
    text.setPosition(0, 0);
    text.setCharacterSize(16);
    text.setString("0");
}
void Score::SetText(std::string score)
{
    text.setString(score);
}
void Score::SetPosition(int x, int y)
{
    text.setPosition(x, y);
}
} // namespace game