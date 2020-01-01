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
    NONE
};

enum class RotateType
{
    UP,
    RIGHT,
    DOWN,
    LEFT,
};

enum class Color
{
    DARK_BLUE,
    GREEN,
    PURPLE,
    SKY_BLUE,
    RED,
    PLUM,
    YELLOW
}; 

enum class KeyType
{
    INVALID,
    UP,
    Down,
    LEFT,
    RIGHT,
    SPACE,
    ESC
};
}  // namespace Tetris
#endif  // !TETRIS_ENUMS_H
