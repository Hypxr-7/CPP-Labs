#include "raylib.h"
#include <cmath>

void DrawBlancmangeCurve(int x1, int y1, int x2, int y2, int depth) {
    if (depth == 0) {
        DrawLine(x1, y1, x2, y2, BLACK);
        return;
    }

    int dx = x2 - x1;
    int dy = y2 - y1;

    int x3 = x1 + dx / 2;
    int y3 = y1 + dy / 2;

    int peakHeight = abs(dx) / 2;
    int y4 = y3 - peakHeight;

    DrawBlancmangeCurve(x1, y1, x3, y4, depth - 1);
    DrawBlancmangeCurve(x3, y4, x2, y2, depth - 1);
}

// ...

int main() {
    InitWindow(800, 600, "Blancmange Curve");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawBlancmangeCurve(50, 550, 750, 550, 6); 

        EndDrawing();
    }

    CloseWindow();
    return 0;
}