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

void SelectionSort() {
    int i, j, min_idx;

    for (i = 0; i < NUM_BARS - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < NUM_BARS; j++)
            if (heights[j] < heights[min_idx])
                min_idx = j;

        std::swap(heights[min_idx], heights[i]);

        // Visualize the sorting
        BeginDrawing();
        ClearBackground(BLACK);
        DrawBars();
        EndDrawing();

    }
}

int main() {
    InitWindow(WIDTH, HEIGHT, "Selection Sort Visualization");
    SetTargetFPS(60);

    GenerateRandomHeights();
    

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawBars();
        EndDrawing();

        if (IsKeyPressed(KEY_SPACE)) {
            SelectionSort();
        }
    }

    CloseWindow();

    return 0;
}