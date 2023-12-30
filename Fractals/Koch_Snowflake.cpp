#include "raylib.h"
#include <cmath>

const int WIDTH = 800;
const int HEIGHT = 800;

void DrawKochCurve(int order, float size, float& x, float& y, float& angle) {
    if (order == 0) {
        x += size * cos(angle);
        y += size * sin(angle);
        DrawPixel(x, y, WHITE);
    } else {
        DrawKochCurve(order - 1, size / 3, x, y, angle);
        angle -= PI / 3;
        DrawKochCurve(order - 1, size / 3, x, y, angle);
        angle += 2 * PI / 3;
        DrawKochCurve(order - 1, size / 3, x, y, angle);
        angle -= PI / 3;
        DrawKochCurve(order - 1, size / 3, x, y, angle);
    }
}

void DrawKochSnowflake(int order, float size) {
    float x = WIDTH / 2 - size / 2;
    float y = HEIGHT / 2 + sqrt(3.0f) * size / 6;
    float angle = -PI / 2;

    for (int i = 0; i < 3; ++i) {
        DrawKochCurve(order, size, x, y, angle);
        angle += 2 * PI / 3;
    }
}

int main() {
    InitWindow(WIDTH, HEIGHT, "Koch Snowflake");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawKochSnowflake(4, WIDTH / 2);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}