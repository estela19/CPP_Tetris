#include <Tetris/Game.h>
#include <Tetris/Tetrimino.h>
#include <effolkronium/random.hpp>

using Random = effolkronium::random_static;

namespace Tetris
{
Tetrimino::Tetrimino()
{
    Ttype = static_cast<TetriminoType>(Random::get(0, 6));
    Rtype = static_cast<RotateType>(Random::get(1, 4));
    Pos.SetX(Game::width_ / 2);
    Pos.SetY(2);
    SetType();
}

bool Tetrimino::MoveDown()
{
    isdown = true;
    Pos.SetY(Pos.GetY() + 1);

    if (!IsValid())
    {
        isdown = false;
        Pos.SetY(Pos.GetY() - 1);
        return false;
    }

    isdown = false;
    return true;
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
    Pos.SetY(Pos.GetY() + 1);
    while (MoveDown())
    {
    }
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
        Rtype = static_cast<RotateType>(++tmp);
    }
    SetType();

    if (!IsValid())
    {
        Rtype = nowtype;
        SetType();
    }
} 

bool Tetrimino::IsValid()
{
    std::size_t minX = 0;
    std::size_t maxX = Game::Get().GetWidth();
    std::size_t maxY = Game::Get().GetHeight();

    for (int i = 0; i < 4; i++)
    {
        Point tmp(Pos);
        tmp.SetX(tmp.GetX() + (type + i)->GetX());
        tmp.SetY(tmp.GetY() + (type + i)->GetY());

        if (tmp.GetY() >= maxY)
        {
            Game::Get().SetIsFloor(true);
            return false;
        }

        else if (tmp.GetX() < minX || tmp.GetX() >= maxX)
        {
            return false;
        }

        else if (Game::Get().GetBoard().Getboard(tmp) != TetriminoType::NONE)
        {
            if (isdown)
            {
                Game::Get().SetIsFloor(true);
            }
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