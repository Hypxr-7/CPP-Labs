#include "game.hpp"

Game::Game(int screenWidth, int screenHeight, const char* title) {
    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(60);
}

Game::~Game() {
    CloseWindow();
}

void Game::Run() {
    while (!WindowShouldClose()) {
        Update();
        BeginDrawing();
            Draw();
        EndDrawing();
    }
}

void Game::Draw() {
    ClearBackground(RAYWHITE);
    ball.Draw();
    Paddle.Draw();
    bricks.Draw();
}

void Game::Update() {
    ball.Update();
    Paddle.Update();
    HandlePaddleBallCollision();
    HandleBallBrickCollision();
}

void Game::HandlePaddleBallCollision() {
    if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), Paddle.GetPad())){
        Vector2 ballSpeed = ball.GetSpeed();
        ballSpeed.y *= -1;
        ball.SetSpeed(ballSpeed);
    }
}

void Game::HandleBallBrickCollision() {
    std::vector<Rectangle> brickRects = bricks.GetBricks();
    std::vector<bool> brickStatus = bricks.GetActive();
    for (int i = 0; i < brickRects.size(); i++) {
        if (brickStatus[i] && CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), brickRects[i])) {
            Vector2 ballSpeed = ball.GetSpeed();
            ballSpeed.y *= -1;
            ball.SetSpeed(ballSpeed);
            bricks.SetActive(i, false);
        }
    }   
}
