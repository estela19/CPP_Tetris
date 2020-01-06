#ifndef _TETRIS_BOARD_H_
#define _TETRIS_BOARD_H_

#include <Tetris/Enums.h>
#include <Tetris/Point.h>

#include <vector>

namespace Tetris
{
class Board
{
 public:
    Board();
    std::vector<TetriminoType>& Getboard();
    TetriminoType& Getboard(std::size_t y, std::size_t x);
    TetriminoType& Getboard(Point pos);
    std::size_t PositionToIdx(std::size_t y, std::size_t x) const;
    bool IsFullRow(std::size_t idx);
    void GetFullRow();
    void UpdateLines();
    void ClearBoard();
    void ClearLine(std::size_t idx);


 private:
    std::vector<TetriminoType> board;
    std::vector<std::size_t> fullIdx;

};
}  // namespace Tetris

#endif  // !_TETRIS_BOARD_H_
