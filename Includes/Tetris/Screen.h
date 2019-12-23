#ifndef _TETRIS_SCREEN_H_
#define _TETRIS_SCREEN_H_

#include <Tetris/Point.h>
#include <Tetris/tetrimino.h>

namespace Tetris
{
class Screen
{
 public:
    void PrintBoard();
    void PrintBlocks(Tetrimino& tetrimino);

 private:
    std::size_t originX = 0;
    std::size_t originY = 2;
    
    const std::size_t width_ = 10;
    const std::size_t height_ = 20;

    const std::size_t scrwidth_ = width_ + 1;
    const std::size_t scrheight_ = height_ + 1;
};
}  // namespace Tetris

#endif  // !_TETRIS_SCREEN_H_
