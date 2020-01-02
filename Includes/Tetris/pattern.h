#ifndef _TETRIS_PATTERN_H_
#define _TETRIS_PATTERN_H_

namespace Tetris
{
inline Point patterns[7][4][4] =  // type / rotate / 4 block unit
    {
        { { Point(0, 1), Point(0, 0), Point(0, -1), Point(0, -2) },
          { Point(-2, 0), Point(-1, 0), Point(0, 0), Point(1, 0) },
          { Point(0, 1), Point(0, 0), Point(0, -1), Point(0, -2) },
          { Point(-2, 0), Point(-1, 0), Point(0, 0), Point(1, 0) } },  // I
        { { Point(0, 1), Point(0, 0), Point(0, -1), Point(-1, -1) },
          { Point(-1, 0), Point(0, 0), Point(1, 0), Point(-1, 1) },
          { Point(0, 1), Point(0, 0), Point(1, 1), Point(0, -1) },
          { Point(-1, 0), Point(0, 0), Point(1, 0), Point(1, -1) } },  // J
        { { Point(-1, 1), Point(0, 1), Point(0, 0), Point(0, -1) },
          { Point(1, 1), Point(-1, 0), Point(0, 0), Point(1, 0) },
          { Point(0, 1), Point(0, 0), Point(0, -1), Point(1, -1) },
          { Point(-1, 0), Point(0, 0), Point(1, 0), Point(-1, -1) } },  // L
        { { Point(-1, 0), Point(0, 0), Point(-1, -1), Point(0, -1) },
          { Point(-1, 0), Point(0, 0), Point(-1, -1), Point(0, -1) },
          { Point(-1, 0), Point(0, 0), Point(-1, -1), Point(0, -1) },
          { Point(-1, 0), Point(0, 0), Point(-1, -1), Point(0, -1) } },  // O
        { { Point(0, 1), Point(0, 0), Point(1, 0), Point(1, -1) },
          { Point(0, 0), Point(1, 0), Point(-1, -1), Point(0, -1) },
          { Point(0, 1), Point(0, 0), Point(1, 0), Point(1, -1) },
          { Point(0, 0), Point(1, 0), Point(-1, -1), Point(0, -1) } },  // S
        { { Point(0, 1), Point(-1, 0), Point(0, 0), Point(0, -1) },
          { Point(0, 1), Point(-1, 0), Point(0, 0), Point(1, 0) },
          { Point(0, 1), Point(0, 0), Point(1, 0), Point(0, -1) },
          { Point(-1, 0), Point(0, 0), Point(1, 0), Point(0, -1) } },  // T
        { { Point(1, 1), Point(0, 0), Point(1, 0), Point(0, -1) },
          { Point(-1, 0), Point(0, 0), Point(0, -1), Point(1, -1) },
          { Point(1, 1), Point(0, 0), Point(1, 0), Point(0, -1) },
          { Point(-1, 0), Point(0, 0), Point(0, -1), Point(1, -1) } }  // Z
    };
}

#endif  // !_TETRIS_PATTERN_H_
