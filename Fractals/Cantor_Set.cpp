#include "raylib.h"

void DrawCantorSet(int y, int x1, int x2, int depth) {
    if (depth == 0) return;

    DrawLine(x1, y, x2, y, BLACK);

    int newY = y - 20;
    int third = (x2 - x1) / 3;
    DrawCantorSet(newY, x1, x1 + third, depth - 1);
    DrawCantorSet(newY, x1 + 2 * third, x2, depth - 1);
}

int main() {
    InitWindow(800, 600, "Cantor Set");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCantorSet(550, 50, 750, 6);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}