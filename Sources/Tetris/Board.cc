#include <Tetris/Board.h>

namespace Tetris
{
Board::Board(std::size_t width, std::size_t height)
    : width_(width), height_(height), board(height_ * width_)
{
}

std::vector<TetriminoType>& Board::Getboard()
{
    return board;
}

TetriminoType& Board::Getboard(std::size_t y, std::size_t x)
{
    return board[PositionToIdx(y, x)];
}

std::size_t Board::PositionToIdx(std::size_t y, std::size_t x)
{
    return width_ * y + x;
}

bool Board::IsFullRow(std::size_t idx)
{
    bool isfull = true;
    for (std::size_t i = 0; i < game->GetWidth(); i++)
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
    for (std::size_t i = 0; i < game->GetHeight(); i++)
    {
        if (IsFullRow(i) == true)
        {
            fullIdx.insert(i);
        }
    }
}

void Board::UpdateBoard()
{
    for (auto i = fullIdx.rbegin(); i != fullIdx.rend(); i++)
    {
        std::size_t full = *i;
        for (std::size_t j = full; j > 0; j--)
        {
            for (std::size_t k = 0; k < width_; k++)
            {
                board[PositionToIdx(j, k)] = board[PositionToIdx(j - 1, k)];
            }
        }
    }
}

void Board::ClearBoard()
{
    board.clear();
}

void Board::ClearLine(std::size_t idx)
{
    for (std::size_t i = 0; i < width_; i++)
    {
        board[PositionToIdx(idx, i)] = TetriminoType::NONE;
    }
}
}  // namespace Tetris