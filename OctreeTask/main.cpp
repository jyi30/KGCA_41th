#include "Launcher.h"
int main()
{
    Launcher game;

    game.player.setPosition(Vector(50, 50, 50), Vector(50, 50, 50));
    game.tree->createTree(Vector(0, 0, 0), Vector(100, 100, 100));

    game.run();
}
