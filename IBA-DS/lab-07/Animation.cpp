#include "raylib.h"
#include "Percolation.hpp"
#include <random>
#include <chrono>
#include <thread>
#include <iostream>

const int screenWidth = 800;
const int screenHeight = 800;

void DrawGrid(Percolation& perc, int n, int cellSize) {
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            int x = col * cellSize;
            int y = row * cellSize;
            if (perc.isOpen(row, col)) {
                if (perc.isFull(row, col)) {
                    DrawRectangle(x, y, cellSize, cellSize, BLUE);
                } else {
                    DrawRectangle(x, y, cellSize, cellSize, WHITE);
                }
            } else {
                DrawRectangle(x, y, cellSize, cellSize, BLACK);
            }
            DrawRectangleLines(x, y, cellSize, cellSize, GRAY);
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 2) { 
        std::cerr << "Usage: " << argv[0] << ' ' << "<N>" << std::endl;
        return 1;
    }
    
    int n = std::stoi(argv[1]);
    const int cellSize = screenWidth / n;
    Percolation perc(n);

    InitWindow(screenWidth, screenHeight, "Percolation Animation");
    SetTargetFPS(60);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, n - 1);

    while (!WindowShouldClose()) {
        if (!perc.percolates()) {
            int row = dis(gen);
            int col = dis(gen);
            if (!perc.isOpen(row, col)) {
                perc.open(row, col);
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawGrid(perc, n, cellSize);
        EndDrawing();

        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Slow down the animation
    }

    CloseWindow();
    return 0;
}

// g++ -std=c++17 -o bin/Animation Animation.cpp -lraylib -lm -lpthread -ldl -lrt -lX11