#include <Tetris/Board.h>
#include <Tetris/Game.h>

#include <algorithm>

namespace Tetris
{
Board::Board()
{
    board.resize(Game::width_ * Game::height_);
    std::fill(board.begin(), board.end(), TetriminoType::NONE);
    fullIdx.clear();
}

std::vector<TetriminoType>& Board::Getboard()
{
    return board;
}

TetriminoType& Board::Getboard(std::size_t y, std::size_t x)
{
    return board[PositionToIdx(y, x)];
}

TetriminoType& Board::Getboard(Point pos)
{
    return board[PositionToIdx(pos.GetY() , pos.GetX())];
}

std::size_t Board::PositionToIdx(std::size_t y, std::size_t x)
{
    return Game::width_ * y + x;
}

bool Board::IsFullRow(std::size_t idx)
{
    bool isfull = true;
    for (std::size_t i = 0; i < Game::width_; i++)
    {
        if (board[PositionToIdx(idx, i)] == TetriminoType::NONE)
        {
            isfull = false;
            break;
        }
    }
    return isfull;
}

void Board::GetFullRow()
{
    for (std::size_t i = 0; i < Game::height_; i++)
    {
        if (IsFullRow(i) == true)
        {
            fullIdx.insert(i);
        }
    }
}

void Board::UpdateLines()
{
    for (auto i = fullIdx.rbegin(); i != fullIdx.rend(); i++)
    {
        std::size_t full = *i;
        for (std::size_t j = full; j > 0; j--)
        {
            for (std::size_t k = 0; k < Game::width_; k++)
            {
                board[PositionToIdx(j, k)] = board[PositionToIdx(j - 1, k)];
            }
        }
    }
    Game::Get().SetClearCnt(fullIdx.size());
    fullIdx.clear();
}

void Board::ClearBoard()
{
    board.clear();
    fullIdx.clear();
    std::fill(board.begin(), board.end(), TetriminoType::NONE);
}

void Board::ClearLine(std::size_t idx)
{
    for (std::size_t i = 0; i < Game::width_; i++)
    {
        board[PositionToIdx(idx, i)] = TetriminoType::NONE;
    }
}
}  // namespace Tetris