#include <Tetris/Game.h>
#include <Tetris/Screen.h>

#include <effolkronium/random.hpp>

namespace Tetris
{
Game& Game::Get()
{
    static Game instance;
    return instance;
}

void Game::Run()
{
    SetCursorInvisible();
    while (true)
    {
        StartTurn();
        while (isFloor == false)
        {
            ProcessTurn();
        }
        EndTurn();

        if (isGameOver == true)
        {
            break;
        }
    }
}

void Game::StartTurn()
{
    isFloor = false;
    tetrimino = new Tetrimino;
    system("cls");
    Screen::PrintBoard();
    Screen::PrintBlocks(*tetrimino);
}

void Game::ProcessTurn()
{
    if (kbhit())
    {
        GetKey();
        Screen::PrintSpace(*tetrimino);
        MoveTetrimino();
        Screen::PrintBlocks(*tetrimino);
    }

    //시간 넘어가면 godown
    static clock_t pretime = 0;

    double tmp = GetDeltaTime(pretime);
    if (tmp > 0.8 - level_ * 0.2)
    {
        Screen::PrintSpace(*tetrimino);
        tetrimino->MoveDown();
        Screen::PrintBlocks(*tetrimino);
        pretime = clock();
    }
}

void Game::EndTurn()
{
    UpdateBoard();
    tetrimino->~Tetrimino();
    if (IsCleard())
    {
        NextStage();
    }

    if (IsGameOver())
    {
        Screen::PrintGameOver();
        isGameOver = true;
    }
}

void Game::NextStage()
{
    clearCnt = 0;
    level_++;
    isFloor = false;
}

bool Game::IsCleard()
{
    if (clearCnt == 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Game::IsGameOver()
{
    if (minBlockPosY <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Game::SetminY(Tetrimino& tetrimino)
{
    int minY = 1000;
    for (int i = 0; i < 4; i++)
    {
        int tetriY = (tetrimino.GetType() + i)->GetY();
        minY = (minY < tetriY ? minY : tetriY);
    }
    minBlockPosY = (minY < minBlockPosY ? minY : minBlockPosY);
}

void Game::UpdateBoard()
{
    Point tmp(tetrimino->GetPos().GetX(), tetrimino->GetPos().GetY());
    for (int i = 0; i < 4; i++)
    {
        board.Getboard(tmp + *(tetrimino->GetType() + i)) =
            tetrimino->GetTType();
    }
    board.UpdateLines();
}

void Game::MoveTetrimino()
{
    if (pushKey == KeyType::LEFT)
    {
        tetrimino->MoveLeft();
    }
    else if (pushKey == KeyType::RIGHT)
    {
        tetrimino->MoveRight();
    }
    else if (pushKey == KeyType::UP)
    {
        tetrimino->Rotate();
    }
    else if (pushKey == KeyType::Down)
    {
        tetrimino->MoveDown();
    }
    else if (pushKey == KeyType::SPACE)
    {
        tetrimino->GoFloor();
    }
    else if (pushKey == KeyType::ESC)
    {
        isPause = true;
    }
}

void Game::GetKey()
{
    int ch = getch();

    if (ch == 0 || ch == 224)
    {
        ch = 256 + getch();
    }

    if (ch == 27)
    {
        pushKey = KeyType::ESC;
    }
    else if (ch == 328)
    {
        pushKey = KeyType::UP;
    }
    else if (ch == 331)
    {
        pushKey = KeyType::LEFT;
    }
    else if (ch == 333)
    {
        pushKey = KeyType::RIGHT;
    }
    else if (ch == 336)
    {
        pushKey = KeyType::Down;
    }
    else if (ch == 32)
    {
        pushKey = KeyType::SPACE;
    }
    else
    {
        pushKey = KeyType::INVALID;
    }
}

clock_t Game::GetDeltaTime(clock_t& pretime)
{
    return static_cast<double>((clock() - pretime) / CLOCKS_PER_SEC);
}

void Game::LineToScore(std::size_t lines)
{
    if (lines == 1)
    {
        AddScore(100);
    }
    else if (lines == 2)
    {
        AddScore(200);
    }
    else if (lines == 3)
    {
        AddScore(500);
    }
    else if (lines == 4)
    {
        AddScore(1000);
    }
}

std::size_t Game::GetScore()
{
    return score_;
}

void Game::AddScore(std::size_t score)
{
    score_ += score;
}

std::size_t Game::GetLevel()
{
    return level_;
}

void Game::SetLevel(std::size_t level)
{
    level_ = level;
}

std::size_t Game::GetClearCnt()
{
    return clearCnt;
}

void Game::AddClearCnt(std::size_t cnt)
{
    clearCnt += cnt;
}

bool Game::GetIsPause()
{
    return isPause;
}

void Game::SetIsPause(bool pause)
{
    isPause = pause;
}

void Game::SetIsFloor(bool floor)
{
    isFloor = floor;
}

void Game::SetTetrimino(Tetrimino* ttetrimino)
{
    tetrimino = ttetrimino;
}

Board& Game::GetBoard()
{
    return board;
}

std::size_t Game::GetOriginX()
{
    return originX;
}

std::size_t Game::GetOriginY()
{
    return originY;
}

std::size_t Game::GetWidth()
{
    return width_;
}

std::size_t Game::GetHeight()
{
    return height_;
}

std::size_t Game::GetScrWidth()
{
    return scrwidth_;
}

std::size_t Game::GetScrHeight()
{
    return scrheight_;
}

void Game::SetCursorInvisible() 
{
    CONSOLE_CURSOR_INFO ci = { 10, FALSE };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
}

const std::size_t Game::originX = 0;
const std::size_t Game::originY = 2;
const std::size_t Game::width_ = 10;
const std::size_t Game::height_ = 20;
const std::size_t Game::scrwidth_ = Game::width_ + 1;
const std::size_t Game::scrheight_ = Game::height_ + 1;

clock_t pretime = 0;
}  // namespace Tetris