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
    Point(int x, int y);

    int GetX() const;
    int GetY() const;
    void SetX(int x);
    void SetY(int y);

    Point operator+(const Point &pt);

    static void GotoXY(int x, int y);
//    static void GotoXY(const int& x, const int& y);
    static void GotoXY(Point pos);
    static void GotoScrXY(int x, int y);
    static Point GetScrPosFromCurPos(const Point &pos);

 private:
    int x_;
    int y_;
};
}  // namespace Tetris

#endif  // !_TETRIS_POINT_H_