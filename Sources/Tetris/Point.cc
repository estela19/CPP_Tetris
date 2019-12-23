#include <conio.h>
#include <cstdlib>
#include <windows.h>

#include <Tetris/Point.h>

namespace Tetris
{
Point::Point(int x, int y) : x_(x), y_(y)
{
    // Do nothing
}

int Point::GetX() const
{
    return x_;
}

int Point::GetY() const
{
    return y_;
}

void Point::SetX(int x)
{
    x_ = x;
}

void Point::SetY(int y)
{
    y_ = y;
}

Point Point::operator+(const Point& pt)
{
    Point tmp(x_ + pt.x_, y_ + pt.y_);
    return tmp;
}

void Point::GotoXY(int x, int y)  // 커서 위치 이동
{
    COORD Pos = { static_cast<short>(x), static_cast<short>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
/*
void Point::GotoXY(const int& x, const int& y)
{
    COORD Pos = { static_cast<short>(x), static_cast<short>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
*/
void Point::GotoXY(Point pos)
{
    GotoXY(pos.GetX(), pos.GetY());
}

void Point::GotoScrXY(int x, int y)
{
    int tmpX = 2 * x + 2;
    COORD Pos = { static_cast<short>(tmpX), static_cast<short>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

Point Point::GetScrPosFromCurPos(
    const Point& pos)  // 배열좌표를 화면좌표로 가져온다.
{
    return Point(2 * pos.x_ + 2, pos.y_);
}
}  // namespace Tetris