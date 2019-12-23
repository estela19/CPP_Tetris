#include <Tetris/Game.h>

namespace Tetris
{
std::size_t Game::GetScore()
{
    return score_;
}

void Game::SetScore(std::size_t score)
{
    score_ = score;
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

void Game::SetClearCnt(std::size_t cnt)
{
    clearCnt = cnt;
}

bool Game::GetIsPause()
{
    return isPause;
}

void Game::SetIsPause(bool pause)
{
    isPause = pause;
}
}  // namespace Tetris