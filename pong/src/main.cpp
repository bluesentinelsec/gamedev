#include "pong.hpp"

int main(int argc, char *argv[])
{
    game::Pong pong;
    pong.start();

    bool isRunning = true;
    while (isRunning)
    {
        isRunning = pong.update();
        pong.render();
    };
    
    pong.exit();

    return 0;
}
