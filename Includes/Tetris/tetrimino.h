#ifndef _TETRIS_TETRIMINO_H_
#define _TETRIS_TETRIMINO_H_

#include <Tetris/Board.h>
#include <Tetris/Enums.h>
#include <Tetris/Pattern.h>
#include <Tetris/Point.h>

namespace Tetris
{
class Board;
class Tetrimino
{
 public:
    Tetrimino();
    ~Tetrimino() = default;
    bool MoveDown();
    void MoveLeft();
    void MoveRight();
    void GoFloor();
    void Rotate();
    bool IsValid();

    void SetType();
    const Point* GetType() const;
    Point GetPos();
    TetriminoType GetTType();
    RotateType GetRType();

 private:
    const Point* type;
    TetriminoType Ttype;
    RotateType Rtype;
    Point Pos;
    bool isdown;
};
}  // namespace Tetris

#endif  // !_TETRIS_TETRIMINO_H_