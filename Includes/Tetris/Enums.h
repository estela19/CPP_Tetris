#ifndef TETRIS_ENUMS_H
#define TETRIS_ENUMS_H

namespace Tetris
{
enum class TetriminoType
{
    NONE,
    I,
    J,
    L,
    O,
    S,
    T,
    Z
};

enum class RotateType
{
    UP,
    RIGHT,
    DOWN,
    LEFT
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
    UP,
    Down,
    LEFT,
    RIGHT,
    SPACE
};
}  // namespace Tetris
#endif  // !TETRIS_ENUMS_H
