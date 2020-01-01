#include <iostream>

#include <Tetris/Game.h>
#include <Tetris/Board.h>
#include <Tetris/screen.h>

using namespace Tetris;

int main()
{
    Game::Get().Run();

    return 0;
}