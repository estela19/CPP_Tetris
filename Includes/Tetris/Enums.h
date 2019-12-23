#ifndef TETRIS_ENUMS_H
#define TETRIS_ENUMS_H

namespace Tetris
{
enum class TetriminoType
{
    I,
    J,
    L,
    O,
    S,
    T,
    Z,

    TypeNums
};

enum class RotateType
{
    UP,
    RIGHT,
    DOWN,
    LEFT
};

enum class KeyType
{
    UP,
    Down,
    LEFT,
    RIGHT,
    SPACE
};
}  // namespace Tetris
#endif  // !TETRIS_ENUMS_H
