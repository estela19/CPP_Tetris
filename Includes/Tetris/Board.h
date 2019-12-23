#ifndef _TETRIS_BOARD_H_
#define _TETRIS_BOARD_H_

#include <Tetris/Game.h>

#include <array>
#include <set>

namespace Tetris
{
using Boardtype = std::array<std::array<int, 20>, 10>;

class Game;
class Board
{
 public:
    Boardtype& GetBoard();
    bool IsFullRow(std::size_t idx);
    void GetFullRow();
    void UpdateBoard();
    void ClearBoard();
    void ClearLine();
    void DeleteLine(std::size_t idx);

 private:
    Game* game;
    Boardtype board;
    std::set<std::size_t> fullIdx;
};
}  // namespace Tetris

#endif  // !_TETRIS_BOARD_H_
