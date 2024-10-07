#include "videomode.hpp"

si::VideoMode::VideoMode(SceneType firstScene)
{
#ifdef __EMSCRIPTEN__
    auto initFlags = SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS | SDL_INIT_AUDIO;
#else
    auto initFlags = SDL_INIT_EVERYTHING;
#endif

    int ret = SDL_Init(initFlags);
    if (ret != 0)
    {
        LOG_FATAL("Unable to initialize SDL2: %s\n", SDL_GetError());
    }

    SDL_DisplayMode mode;
    SDL_GetDesktopDisplayMode(0, &mode);

#ifdef __EMSCRIPTEN__
    auto windowFlags = SDL_WINDOW_ALLOW_HIGHDPI;
#else
    auto windowFlags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI;
#endif

    window = SDL_CreateWindow("Space Invaders", 0, 0, mode.w, mode.h, windowFlags);
    if (window == nullptr)
    {
        LOG_FATAL("unable to create SDL window: %s\n", SDL_GetError());
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        LOG_FATAL("unable to create SDL renderer: %s\n", SDL_GetError());
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    ret = SDL_RenderSetLogicalSize(renderer, si::Globals::screenWidth, si::Globals::screenHeight);
    if (ret != 0)
    {
        LOG_FATAL("unable to set render logical size: %s\n", SDL_GetError());
    }

    int imgFlags = IMG_INIT_PNG;
    ret = IMG_Init(imgFlags);
    if (ret != imgFlags)
    {
        LOG_FATAL("unable to initialize SDL2_image: %s\n", SDL_GetError());
    }

    ret = TTF_Init();
    if (ret != 0)
    {
        LOG_FATAL("unable to initialize SDL2_ttf: %s\n", SDL_GetError());
    }

    ret = Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048);
    if (ret != 0)
    {
        LOG_FATAL("unable to initialize SDL2_mixer: %s\n", SDL_GetError());
    }

    currentScene = SceneFactory::CreateScene(firstScene);
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
    isRunning = currentScene->Update(0, &event);
    currentScene->Render(renderer);
    return isRunning;
}
