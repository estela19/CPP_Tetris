#ifndef _TETRIS_GAME_H_
#define _TETRIS_GAME_H_

#include <time.h>
#include <iostream>
#include <vector>

#include <Tetris/Board.h>
#include <Tetris/Tetrimino.h>

namespace Tetris
{
class Tetrimino;
class Game
{
 public:
    static Game& Get();
    void Run();
    void StartTurn();
    void ProcessTurn();
    void EndTurn();

    void NextStage();
    bool IsCleard();
    bool IsGameOver();
    void SetminY(Tetrimino& tetrimino);
    void UpdateBoard();
    void MoveTetrimino();

    void GetKey();
    static clock_t GetDeltaTime(clock_t& pretime);
    void Game::LineToScore(std::size_t lines);

    std::size_t GetScore() const;
    void AddScore(std::size_t score);
    std::size_t GetLevel() const;
    void SetLevel(std::size_t level);
    std::size_t GetClearCnt() const;
    void AddClearCnt(std::size_t cnt);
    bool GetIsPause() const;
    void SetIsPause(bool pause);
    void SetIsFloor(bool floor);
    void SetTetrimino(Tetrimino* ttetrimino);

    Board& GetBoard();

    void SetMinY(Tetrimino& tetrimino);

    std::size_t GetOriginX() const;
    std::size_t GetOriginY() const;
    std::size_t GetWidth() const;
    std::size_t GetHeight() const;
    std::size_t GetScrWidth() const;
    std::size_t GetScrHeight() const;

 private:
    void SetCursorInvisible();
 
public:
    static const std::size_t originX;
    static const std::size_t originY;
    static const std::size_t width_;
    static const std::size_t height_;
    static const std::size_t scrwidth_;
    static const std::size_t scrheight_;

 private:
    Game() = default;
    Board board;
    Tetrimino* tetrimino;

    std::size_t score_;
    std::size_t level_ = 1;
    bool isPause = false;
    std::size_t clearCnt = 0;
    bool isFloor = false;
    bool isGameOver = false;
    KeyType pushKey = KeyType::INVALID;

    int minBlockPosY = height_;
};
}  // namespace Tetris

#endif  // !_TETRIS_GAME_H_
