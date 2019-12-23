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
}

void Tetrimino::MoveLeft()
{
    std::size_t minX = game->GetOriginX();

    if (Pos.GetX() > minX + 1)
    {
        Pos.SetX(Pos.GetX() - 1);
    }
}

void Tetrimino::MoveRight()
{
    std::size_t maxX = game->GetOriginX() + game->GetScrWidth();

    if (Pos.GetX() < maxX - 1)
    {
        Pos.SetX(Pos.GetX() + 1);
    }
}

void Tetrimino::GoFloor()
{
}

void Tetrimino::Rotate()
{
}

void Tetrimino::SetType()
{
    type = &patterns[static_cast<int>(Ttype)][static_cast<int>(Rtype)][0];
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