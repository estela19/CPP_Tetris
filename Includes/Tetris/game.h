#ifndef _TETRIS_GAME_H_
#define _TETRIS_GAME_H_

#include <iostream>
#include <vector>

#include <Tetris/Tetrimino.h>

namespace Tetris
{
class Tetrimino;
class Game
{
 public:
    std::vector<Tetrimino*> blocks;
    std::size_t GetScore();
    void SetScore(std::size_t score);
    std::size_t GetLevel();
    void SetLevel(std::size_t level);
    std::size_t GetClearCnt();
    void SetClearCnt(std::size_t cnt);
    bool GetIsPause();
    void SetIsPause(bool pause);

    std::size_t GetOriginX();
    std::size_t GetOriginY();
    std::size_t GetWidth();
    std::size_t GetHeight();
    std::size_t GetScrWidth();
    std::size_t GetScrHeight();

 private:
    std::size_t score_;
    std::size_t level_;
    bool isPause;
    std::size_t clearCnt;

    std::size_t originX = 0;
    std::size_t originY = 2;
    const std::size_t width_ = 10;
    const std::size_t height_ = 20;
    const std::size_t scrwidth_ = width_ + 1;
    const std::size_t scrheight_ = height_ + 1;
};
}  // namespace Tetris

#endif  // !_TETRIS_GAME_H_
