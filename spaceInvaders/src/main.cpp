#include "tileson.hpp"
#include "videomode.hpp"
#include <cstdlib>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

static si::VideoMode vm;

void tickFrame()
{
    vm.Update();
}

int main(int argc, char *argv[])
{
    tson::Tileson t;
#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(tickFrame, 60, 1);
#else
    while (vm.Update())
    {
    };
#endif
    return EXIT_SUCCESS;
}
/*
 * scratch pad:
 * need to add keyboard input, for testing
 * need to package macOS release build
 * need to setup web build
 * make scenes in tiled (title, game, win/lose)
 * add tiled parser
 * add scenes
 * add actors (player, aliens, lasers) - keep it primitive for momentum
 * add cli so we can enable different settings:
 *      tiled map to load
 *      windowed or full screen
 *      debug logs
 * End state: MVP engine for macOS and web powered by SDL2 and Tiled
 * Next state: add gamepad support and Windows build
 */
