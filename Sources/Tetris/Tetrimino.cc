#include <Tetris/Tetrimino.h>

namespace Tetris
{
Game& Tetrimino::GetGame()
{
    return *game;
}

Board& Tetrimino::GetBoard()
{
    return *board;
}

void Tetrimino::MoveDown()
{
    Pos.SetY(Pos.GetY() + 1);

    if (!IsValid())
    {
        Pos.SetY(Pos.GetY() - 1);
    }
}

void Tetrimino::MoveLeft()
{
    Pos.SetX(Pos.GetX() - 1);

    if (!IsValid())
    {
        Pos.SetX(Pos.GetX() + 1);
    }
}

void Tetrimino::MoveRight()
{
    Pos.SetX(Pos.GetX() + 1);

    if (!IsValid())
    {
        Pos.SetX(Pos.GetX() - 1);
    }
}

void Tetrimino::GoFloor()
{
    do
    {
        MoveDown();
    } while (IsValid());
}

void Tetrimino::Rotate()
{
    RotateType nowtype = Rtype;

    if (Rtype == RotateType::LEFT)
    {
        Rtype = RotateType::UP;
    }
    else
    {
        int tmp = static_cast<int>(Rtype);
        Rtype = static_cast<RotateType>(tmp++);
    }

    if (!IsValid())
    {
        Rtype = nowtype;
    }
}

bool Tetrimino::IsValid()
{
    std::size_t minX = game->GetOriginX();
    std::size_t maxX = game->GetOriginX() + game->GetScrWidth();
    std::size_t maxY = game->GetOriginY() + game->GetScrHeight();

    Point tmp(Pos);
    for (int i = 0; i < 4; i++)
    {
        tmp.SetX(tmp.GetX() + (type + i)->GetX());
        tmp.SetY(tmp.GetY() + (type + i)->GetY());
        if (board->PositionToIdx(tmp.GetX(), tmp.GetY()) != 0)
        {
            return false;
        }

        else if (tmp.GetX() <= minX || tmp.GetX() >= maxX || tmp.GetY() >= maxY)
        {
            return false;
        }
    }

    return true;
}

void Tetrimino::SetType()
{
    type = &patterns[static_cast<int>(Ttype)][static_cast<int>(Rtype)][0];
}

const Point* Tetrimino::GetType() const
{
    return type;
}

Point Tetrimino::GetPos()
{
    return Pos;
}

TetriminoType Tetrimino::GetTType()
{
    return Ttype;
}

RotateType Tetrimino::GetRType()
{
    return Rtype;
}

}  // namespace Tetris