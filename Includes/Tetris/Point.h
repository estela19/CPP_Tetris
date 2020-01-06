#ifndef _TETRIS_POINT_H_
#define _TETRIS_POINT_H_

#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<cstdlib>

namespace Tetris
{
class Point
{
 public:
    Point();
    Point(int x, int y);

    int GetX() const;
    int GetY() const;
    void SetX(int x);
    void SetY(int y);

    Point operator+(const Point &pt) const;

    static void GotoXY(int x, int y);
    static void GotoXY(const Point& pos);
    static void GotoScrXY(int x, int y);

 private:
    int x_;
    int y_;
};
}  // namespace Tetris

#endif  // !_TETRIS_POINT_H_