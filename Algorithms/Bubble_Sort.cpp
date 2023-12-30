#include "raylib.h"
#include <vector>
#include <algorithm>
#include <cstdlib>

const int WIDTH = 800;
const int HEIGHT = 600;
const int NUM_BARS = 100;
const int BAR_WIDTH = WIDTH / NUM_BARS;

std::vector<int> heights(NUM_BARS);

void GenerateRandomHeights() {
    for (int& height : heights) {
        height = GetRandomValue(50, HEIGHT - 50);
    }
}

void DrawBars() {
    for (int i = 0; i < NUM_BARS; ++i) {
        DrawRectangle(i * BAR_WIDTH, HEIGHT - heights[i], BAR_WIDTH, heights[i], WHITE);
    }
}

void BubbleSort() {
    for (int i = 0; i < NUM_BARS - 1; ++i) {
        for (int j = 0; j < NUM_BARS - i - 1; ++j) {
            if (heights[j] > heights[j + 1]) {
                std::swap(heights[j], heights[j + 1]);

                // Visualize the sorting
                BeginDrawing();
                ClearBackground(BLACK);
                DrawBars();
                EndDrawing();
            }
        }
    }
}

int main() {
    InitWindow(WIDTH, HEIGHT, "Bubble Sort Visualization");
    SetTargetFPS(60);

    GenerateRandomHeights();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawBars();
        EndDrawing();

        if (IsKeyPressed(KEY_SPACE)) {
            BubbleSort();
        }
    }

    CloseWindow();

    return 0;
}