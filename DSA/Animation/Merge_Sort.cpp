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

void Merge(int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    std::vector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = heights[low + i];
    for (j = 0; j < n2; j++)
        R[j] = heights[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            heights[k] = L[i];
            i++;
        } else {
            heights[k] = R[j];
            j++;
        }
        k++;

        // Visualize the sorting
        BeginDrawing();
        ClearBackground(BLACK);
        DrawBars();
        EndDrawing();
    }

    while (i < n1) {
        heights[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        heights[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        MergeSort(low, mid);
        MergeSort(mid + 1, high);

        Merge(low, mid, high);
    }
}

int main() {
    InitWindow(WIDTH, HEIGHT, "Merge Sort Visualization");
    SetTargetFPS(60);

    GenerateRandomHeights();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawBars();
        EndDrawing();

        if (IsKeyPressed(KEY_SPACE)) {
            MergeSort(0, NUM_BARS - 1);
        }
    }

    CloseWindow();

    return 0;
}