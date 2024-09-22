#include <cstdlib>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main(int argc, char *argv[])
{
    SDL_Log("SDL2 test");
    IMG_Init(0);
    Mix_CloseAudio();
    TTF_CloseFont(nullptr);
    json j = {
        {"pi", 3.141}, {"happy", true}, {"name", "Niels"}, {"nothing", nullptr}, {"answer", {{"everything", 42}}}};
    
    return EXIT_SUCCESS;
}
