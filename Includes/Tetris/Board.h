#ifndef _TETRIS_BOARD_H_
#define _TETRIS_BOARD_H_

#include <Tetris/game.h>

#include <array>

namespace Tetris
{
class Board
{
    using Boardtype = std::array<std::array<int, 10>, 20>;

 public:
    Boardtype& GetBoard();
    bool IsFullRow(std::size_t idx);
    bool HasFullRow();

 private:
    Game* game;
    Boardtype board;
};
}  // namespace Tetris

#endif  // !_TETRIS_BOARD_H_
