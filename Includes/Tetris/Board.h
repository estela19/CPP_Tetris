#ifndef _TETRIS_BOARD_H_
#define _TETRIS_BOARD_H_

#include <Tetris/Enums.h>
#include <Tetris/Game.h>

#include <vector>
#include <set>

namespace Tetris
{
class Game;
class Board
{
 public:
    Board(std::size_t width, std::size_t height);
    std::vector<TetriminoType>& Getboard();
    TetriminoType& Getboard(std::size_t y, std::size_t x);
    std::size_t PositionToIdx(std::size_t y, std::size_t x);
    bool IsFullRow(std::size_t idx);
    void GetFullRow();
    void UpdateBoard();
    void ClearBoard();
    void ClearLine(std::size_t idx);


 private:
    const std::size_t width_;
    const std::size_t height_;
    Game* game;
    std::vector<TetriminoType> board;
    std::set<std::size_t> fullIdx;

};
}  // namespace Tetris

#endif  // !_TETRIS_BOARD_H_
