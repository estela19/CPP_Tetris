#include <windows.h>
#include <stdexcept>

#include <Tetris/Game.h>
#include <Tetris/Point.h>
#include <Tetris/Screen.h>
#include <Tetris/tetrimino.h>

#define COL GetStdHandle(STD_OUTPUT_HANDLE)
#define DARK_BLUE SetConsoleTextAttribute(COL, 0x0001);
#define GREEN SetConsoleTextAttribute(COL, 0x0002);
#define PURPLE SetConsoleTextAttribute(COL, 0x0005);
#define SKY_BLUE SetConsoleTextAttribute(COL, 0x000b);
#define RED SetConsoleTextAttribute(COL, 0x000c);
#define PLUM SetConsoleTextAttribute(COL, 0x000d);
#define YELLOW SetConsoleTextAttribute(COL, 0x000e);
#define ORIGINAL SetConsoleTextAttribute(COL, 0x0007);

namespace Tetris
{
void Screen::PrintBoard()
{
    // Print board struct
    for (std::size_t i = 0; i < Game::height_; i++)
    {
        Point::GotoScrXY(0 , i);
        ORIGINAL std::cout << "в╔";
        Point::GotoScrXY(Game::scrwidth_, i);
        ORIGINAL std::cout << "в╔";
    }

    for (std::size_t i = 0; i <= Game::scrwidth_; i++)
    {
        Point::GotoScrXY(i, Game::height_);
        ORIGINAL std::cout << "в╔";
    }

    // Print board
    Board& pboard = Game::Get().GetBoard();
    for (std::size_t i = 0; i < Game::width_; i++)
    {
        for (std::size_t j = 0; j < Game::height_; j++)
        {
         //   std::size_t x = i + 1;
         //   std::size_t y = j + 1;

            Point::GotoScrXY(i + 1, j);
            if (pboard.Getboard(j, i) == TetriminoType::I)
            {
                DARK_BLUE std::cout << "бс";
            }
            else if (pboard.Getboard(j, i) == TetriminoType::J)
            {
                GREEN std::cout << "бс";
            }
            else if (pboard.Getboard(j, i) == TetriminoType::L)
            {
                PURPLE std::cout << "бс";
            }
            else if (pboard.Getboard(j, i) == TetriminoType::O)
            {
                SKY_BLUE std::cout << "бс";
            }
            else if (pboard.Getboard(j, i) == TetriminoType::S)
            {
                RED std::cout << "бс";
            }
            else if (pboard.Getboard(j, i) == TetriminoType::T)
            {
                PLUM std::cout << "бс";
            }
            else if (pboard.Getboard(j, i) == TetriminoType::Z)
            {
                YELLOW std::cout << "бс";
            }
        }
    }
}

void Screen::PrintBlocks(Tetrimino& tetrimino)
{
    for (int i = 0; i < 4; i++)
    {
        Point::GotoScrXY(
            tetrimino.GetPos().GetX() + (tetrimino.GetType() + i)->GetX() + 1,
            tetrimino.GetPos().GetY() + (tetrimino.GetType() + i)->GetY());

        if (tetrimino.GetTType() == TetriminoType::I)
        {
            DARK_BLUE std::cout << "бс";
        }
        else if (tetrimino.GetTType() == TetriminoType::J)
        {
            GREEN std::cout << "бс";
        }
        else if (tetrimino.GetTType() == TetriminoType::L)
        {
            PURPLE std::cout << "бс";
        }
        else if (tetrimino.GetTType() == TetriminoType::O)
        {
            SKY_BLUE std::cout << "бс";
        }
        else if (tetrimino.GetTType() == TetriminoType::S)
        {
            RED std::cout << "бс";
        }
        else if (tetrimino.GetTType() == TetriminoType::T)
        {
            PLUM std::cout << "бс";
        }
        else if (tetrimino.GetTType() == TetriminoType::Z)
        {
            YELLOW std::cout << "бс";
        }
        else
        {
            throw std::logic_error("tetrimino type error");
        }
    }
}

void Screen::PrintSpace(Tetrimino& tetrimino)
{
    for (int i = 0; i < 4; i++)
    {
        Point::GotoScrXY(
            tetrimino.GetPos().GetX() + (tetrimino.GetType() + i)->GetX() + 1,
            tetrimino.GetPos().GetY() + (tetrimino.GetType() + i)->GetY());

        std::cout << (" ");
    }
}

}  // namespace Tetris