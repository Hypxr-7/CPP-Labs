#include <raylib.h>
#include "game.hpp"

int main() {
    Game game(800, 450, "Breakout in Raylib!");
    game.Run();    

    return 0;
}