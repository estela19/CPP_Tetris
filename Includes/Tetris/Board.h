#ifndef _TETRIS_BOARD_H_
#define _TETRIS_BOARD_H_

#include <Tetris/Game.h>

#include <vector>
#include <set>

namespace Tetris
{
class Game;
class Board
{
 public:
    std::vector<int>& GetBoard();
    std::size_t PositionToIdx();
    bool IsFullRow(std::size_t idx);
    void GetFullRow();
    void UpdateBoard();
    void ClearBoard();
    void ClearLine();
    void DeleteLine(std::size_t idx);


 private:
    const std::size_t width;
    const std::size_t height;
    Game* game;
    std::vector<int> board;
    std::set<std::size_t> fullIdx;
};
}  // namespace Tetris

#endif  // !_TETRIS_BOARD_H_
