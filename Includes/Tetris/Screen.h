#ifndef _TETRIS_SCREEN_H_
#define _TETRIS_SCREEN_H_

#include <Tetris/Point.h>
#include <Tetris/Tetrimino.h>


namespace Tetris
{
class Screen
{
 public:
    static void PrintBoard();
    static void PrintBlocks(const Tetrimino& tetrimino);
    static void PrintSpace(const Tetrimino& tetrimino);
    static void PrintGameOver();

};
}  // namespace Tetris

#endif  // !_TETRIS_SCREEN_H_
