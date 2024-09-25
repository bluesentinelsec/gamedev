#include "tileson.hpp"
#include "videomode.hpp"
#include <cstdlib>

int main(int argc, char *argv[])
{
    tson::Tileson t;
    si::VideoMode vm;
    while (vm.Update())
    {
    };
    return EXIT_SUCCESS;
}
/*
 * scratch pad:
 * next need to implement media wrappers:
 * texture
 * font
 * music
 * sound
 */
