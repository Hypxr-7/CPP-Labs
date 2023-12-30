#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Pong Game");

    // Paddle A
    Rectangle paddleA = { 50, screenHeight / 2 - 50, 20, 100 };
    // Paddle B
    Rectangle paddleB = { screenWidth - 70, screenHeight / 2 - 50, 20, 100 };

    // Ball
    Vector2 ballPosition = { screenWidth / 2, screenHeight / 2 };
    float ballRadius = 10.0f;
    Vector2 ballSpeed = { -5.0f, -5.0f };

    // Scores
    int scoreA = 0;
    int scoreB = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Move Paddle A
        if (IsKeyDown(KEY_W) && paddleA.y > 0) paddleA.y -= 5.0f;
        if (IsKeyDown(KEY_S) && paddleA.y < screenHeight - paddleA.height) paddleA.y += 5.0f;

        // Move Paddle B
        if (IsKeyDown(KEY_UP) && paddleB.y > 0) paddleB.y -= 5.0f;
        if (IsKeyDown(KEY_DOWN) && paddleB.y < screenHeight - paddleB.height) paddleB.y += 5.0f;

        // Move Ball
        ballPosition.x += ballSpeed.x;
        ballPosition.y += ballSpeed.y;

        // Collision Logic
        if (ballPosition.y > screenHeight - ballRadius || ballPosition.y < ballRadius) ballSpeed.y *= -1;

        if (CheckCollisionCircleRec(ballPosition, ballRadius, paddleA)) {
            ballSpeed.x *= -1;
            float diff = (ballPosition.y - (paddleA.y + paddleA.height / 2)) / (paddleA.height / 2);
            ballSpeed.y = diff * 5.0f;
        }

        if (CheckCollisionCircleRec(ballPosition, ballRadius, paddleB)) {
            ballSpeed.x *= -1;
            float diff = (ballPosition.y - (paddleB.y + paddleB.height / 2)) / (paddleB.height / 2);
            ballSpeed.y = diff * 5.0f;
        }
        // Score Logic
        if (ballPosition.x < 0) {
            ballPosition = { screenWidth / 2, screenHeight / 2 };
            scoreB++;
        }
        if (ballPosition.x > screenWidth) {
            ballPosition = { screenWidth / 2, screenHeight / 2 };
            scoreA++;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(paddleA, BLACK);
        DrawRectangleRec(paddleB, BLACK);
        DrawCircleV(ballPosition, ballRadius, BLACK);
        DrawText(TextFormat("Player A: %i", scoreA), 10, 10, 20, BLACK);
        DrawText(TextFormat("Player B: %i", scoreB), screenWidth - 150, 10, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}