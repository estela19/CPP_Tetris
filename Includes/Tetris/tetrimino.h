#ifndef _TETRIS_TETRIMINO_H_
#define _TETRIS_TETRIMINO_H_

#include <Tetris/Board.h>
#include <Tetris/Point.h>
#include <Tetris/Enums.h>
#include <Tetris/Pattern.h>
#include <Tetris/Game.h>

namespace Tetris
{
class Game;
class Board;
class Tetrimino
{
 public:
    Game& GetGame();
    Board& GetBoard();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void GoFloor();
    void Rotate();
    
    void SetType();
    Point GetPos();
    TetriminoType GetTType();
    RotateType GetRType();


 private:
    Game* game;
    Board* board;
    const Point* type;
    TetriminoType Ttype;
    RotateType Rtype;
    bool isfloor = false;
    Point Pos;
};
}  // namespace Tetris

#endif  // !_TETRIS_TETRIMINO_H_