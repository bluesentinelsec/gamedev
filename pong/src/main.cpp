#include "pong.hpp"

#include "pathutils.hpp"
#include "logger.hpp"

void initLogger();

int main(int argc, char *argv[])
{
    game::pathutils::InitFilesystem(argv[0]);
    initLogger();

    game::Pong pong;
    pong.start();

    bool isRunning = true;
    while (isRunning)
    {
        isRunning = pong.update();
    };
    
    pong.exit();

    return 0;
}

void initLogger()
{
#ifdef Release
    logger::Logger::getInstance().setLogLevel(logger::LogLevel::INFO);
#else
    logger::Logger::getInstance().setLogLevel(logger::LogLevel::DEBUG);
#endif
}

/*
 * TODO:
 * 1. Create a simple title screen (start and quit choices only)
 *      - Use Tiled to design it, but just implement it in code since its small
 *
 * 2. Start the play screen:
 *      - add all entities to the screen
 *
 * 3. Write down the game rules.
 *
 * 4. Implement the game rules (player, ball, CPU, player score, CPU score)
 *
 * 5. Add 'you win/lose' message plus 'again or exit'
 *
 * 6. Add music and sound
 *
 * 7. Fit and finish
 */