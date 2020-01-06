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
    return board[PositionToIdx(pos.GetY(), pos.GetX())];
}

std::size_t Board::PositionToIdx(std::size_t y, std::size_t x) const
{
    return Game::width_ * y + x;
}

bool Board::IsFullRow(std::size_t idx)
{
    for (std::size_t i = 0; i < Game::width_; i++)
    {
        if (board[PositionToIdx(idx, i)] == TetriminoType::NONE)
        {
            return false;
        }
    }
    return true;
}

void Board::GetFullRow()
{
    for (std::size_t i = 0; i < Game::height_; i++)
    {
        if (IsFullRow(i) == true)
        {
            fullIdx.push_back(i);
        }
    }
}

void Board::UpdateLines()
{
    GetFullRow();
    int size = fullIdx.size();
    for (int i = 0; i < size; i++)
    {
        std::size_t full = fullIdx.back();
        fullIdx.pop_back();
        for (std::size_t j = full; j > 0; j--)
        {
            for (std::size_t k = 0; k < Game::width_; k++)
            {
                board[PositionToIdx(j, k)] = board[PositionToIdx(j - 1, k)];
            }
        }
        for (auto& k : fullIdx)
        {
            k++;
        }
    }
    Game::Get().AddClearCnt(size);
    Game::Get().LineToScore(size);
    fullIdx.clear();
}

void Board::ClearBoard()
{
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