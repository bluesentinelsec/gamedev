#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

#include <string>

namespace si
{
class sdlFont
{
  public:
    sdlFont() = default;

    void init(int xPos, int yPos, const std::string &aPath, int aSize, SDL_Color aColor, const std::string &message,
              SDL_Renderer *ren)
    {
        x = xPos;
        y = yPos;
        path = aPath;
        size = aSize;
        color = aColor;
        renderer = ren;
        str = message;

        font = TTF_OpenFont(path.c_str(), size);
        SDL_assert(font != nullptr);

        surface = TTF_RenderText_Solid(font, str.c_str(), color);
        SDL_assert(surface != nullptr);

        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_assert(texture != nullptr);

        SDL_FreeSurface(surface);
        TTF_CloseFont(font);
    }

    ~sdlFont()
    {
        SDL_assert(texture != nullptr);

        SDL_DestroyTexture(texture);
    };

    SDL_Texture *get()
    {
        return texture;
    }

    void draw()
    {
        SDL_assert(renderer != nullptr);
        SDL_assert(texture != nullptr);
        int srcWidth = 0;
        int srcHeight = 0;
        int ret = SDL_QueryTexture(texture, nullptr, nullptr, &srcWidth, &srcHeight);
        SDL_assert(ret == 0);
        SDL_Rect dst{.x = x, .y = y, .w = srcWidth, .h = srcHeight};
        SDL_RenderCopy(renderer, texture, nullptr, &dst);
    }

  private:
    TTF_Font *font = nullptr;
    SDL_Surface *surface = nullptr;
    SDL_Texture *texture = nullptr;
    SDL_Renderer *renderer;
    std::string str;
    std::string lastStr;
    SDL_Color color{.r = 0, .g = 0, .b = 0, .a = 255};
    std::string path;
    int size = 32;
    int x = 0;
    int y = 0;
};
} // namespace si