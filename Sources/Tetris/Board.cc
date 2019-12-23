#include <Tetris/Board.h>

namespace Tetris
{
Boardtype& Board::GetBoard()
{
    return board;
}

bool Board::IsFullRow(std::size_t idx)
{
    bool isfull = true;
    for (std::size_t i = 0; i < game->GetWidth(); i++)
    {
        if (board[idx][i] == 0)
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
        }
    }
}

void Board::ClearBoard()
{
    for (int i = 0; i < game->GetHeight(); i++)
    {
      //  board[i].clear();
    }
}

void Board::DeleteLine(std::size_t idx)
{
    board[idx].fill(0);
}
}  // namespace Tetris