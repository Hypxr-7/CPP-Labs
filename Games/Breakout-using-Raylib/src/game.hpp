#pragma once

#include <raylib.h>
#include "ball.hpp"
#include "paddle.hpp"
#include "bricks.hpp"

class Game {
private:
    Ball ball;
    Paddle Paddle;
    Bricks bricks;
    void Draw();
    void Update();
    void HandlePaddleBallCollision();
    void HandleBallBrickCollision();
public:
    Game(int screenWidth, int screenHeight, const char* title);
    ~Game();
    void Run();
};