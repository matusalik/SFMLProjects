#include <iostream>
#include "Game.h"
int main()
{
    std::srand(std::time(NULL));
    //Init Game engine
    Game game;
    //Game loop
    while (game.running()) {
        //Update
        game.update();
        //Render
        game.render();
    }
    return 0;
}
