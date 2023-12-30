#include "raylib.h"
#include <cmath>

const int WIDTH = 800;
const int HEIGHT = 800;

int main() {
    InitWindow(WIDTH, HEIGHT, "Gradient Window");

    float time = 0.0f;

    while (!WindowShouldClose()) {
        time += GetFrameTime();

        float density = 0.5f + 0.5f * std::sin(time);

        Image gradient = GenImageGradientRadial(WIDTH, HEIGHT, density, BLACK, WHITE);
        Texture2D texture = LoadTextureFromImage(gradient);
        UnloadImage(gradient);

        BeginDrawing();
        ClearBackground(WHITE);
        DrawTexture(texture, 0, 0, WHITE);
        EndDrawing();

        UnloadTexture(texture);
    }

    CloseWindow();

    return 0;
}