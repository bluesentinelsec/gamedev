#include "videomode.hpp"

si::VideoMode::VideoMode()
{
    int ret = SDL_Init(SDL_INIT_EVERYTHING);
    SDL_assert(ret == 0);

    SDL_DisplayMode mode;
    SDL_GetDesktopDisplayMode(0, &mode);

    auto windowFlags = SDL_WINDOW_RESIZABLE;
    window = SDL_CreateWindow("Space Invaders", 0, 0, mode.w, mode.h, windowFlags);
    SDL_assert(window != nullptr);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_assert(renderer != nullptr);

    ret = SDL_RenderSetLogicalSize(renderer, si::Globals::screenWidth, si::Globals::screenHeight);
    SDL_assert(ret == 0);

    int imgFlags = IMG_INIT_PNG;
    ret = IMG_Init(imgFlags);
    SDL_assert(ret == imgFlags);

    ret = TTF_Init();
    SDL_assert(ret == 0);

    ret = Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048);
    SDL_assert(ret == 0);
}

si::VideoMode::~VideoMode()
{
    Mix_CloseAudio();
    TTF_Quit();
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool si::VideoMode::Update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            isRunning = false;
            break;
        }
    }
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(16);

    return isRunning;
}
