#include "Game.h"

int main()
{
    // Initialise randome seed
    srand(static_cast<unsigned>(time(0)));

    // Initialise game object
    Game game;

    // Game loop
    while (game.running())
    {
        game.update();
        game.render();
    }

    // End of application
    return 0;
}