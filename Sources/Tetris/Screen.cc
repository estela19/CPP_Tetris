#include <windows.h>
#include <stdexcept>

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
void Screen::TypeToColor()
{

}

void Screen::PrintBoard()
{
    // Print board struct
    for (std::size_t i = 0; i < height_; i++)
    {
        Point::GotoScrXY(originX, originY + i);
        std::cout << "в╔";
        Point::GotoScrXY(originX + scrwidth_, originY + i);
        std::cout << "в╔";
    }

    for (std::size_t i = 0; i < scrwidth_; i++)
    {
        Point::GotoScrXY(originX + i, originY + height_);
        std::cout << "в╔";
    }

    // Print board
    auto& sboard = Game::GetBoard();
}

void Screen::PrintBlocks(Tetrimino& tetrimino)
{
    for (int i = 0; i < 4; i++)
    {
        if (tetrimino.GetPos().GetY() > 0)
        {
            Point::GotoScrXY(tetrimino.GetPos().GetX(),
                             tetrimino.GetPos().GetY());

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
}
}  // namespace Tetris