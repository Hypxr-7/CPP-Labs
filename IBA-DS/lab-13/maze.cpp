#include <algorithm>
#include <random>
#include <thread>
#include <vector>

#include "raylib.h"

// Directions
enum Direction { NORTH, EAST, SOUTH, WEST };

class Maze {
private:
    int cols, rows;
    std::vector<std::vector<bool>> north, east, south, west, visited;
    bool isDone = false;
    const int cellSize = 20;

    void init() {
        // Nothing has been visited yet
        visited.assign(cols + 2, std::vector(rows + 2, false));

        // All walls stand initially
        north.assign(cols + 2, std::vector(rows + 2, true));
        east.assign(cols + 2, std::vector(rows + 2, true));
        south.assign(cols + 2, std::vector(rows + 2, true));
        west.assign(cols + 2, std::vector(rows + 2, true));

        // Mark border cells as visited
        for (int col = 0; col < cols + 2; col++)
            visited[col][0] = visited[col][rows + 1] = true;

        for (int row = 0; row < rows + 2; row++)
            visited[0][row] = visited[cols + 1][row] = true;
    }

    void generate(const int col, const int row) {
        visited[col][row] = true;

        // Generate random directions
        std::vector directions = {NORTH, EAST, SOUTH, WEST};
        std::shuffle(directions.begin(), directions.end(), std::mt19937(std::random_device{}()));

        // find coordinates of the next cell to visit
        for (const Direction dir : directions) {
            int newCol = col, newRow = row;

            switch (dir) {
            case NORTH: newRow++;
                break;
            case EAST: newCol++;
                break;
            case SOUTH: newRow--;
                break;
            case WEST: newCol--;
                break;
            }

            // If the cell has not been visited, break the wall and perform recursive search on that cell
            if (!visited[newCol][newRow]) {
                switch (dir) {
                case NORTH:
                    north[col][row] = south[newCol][newRow] = false;
                    break;
                case EAST:
                    east[col][row] = west[newCol][newRow] = false;
                    break;
                case SOUTH:
                    south[col][row] = north[newCol][newRow] = false;
                    break;
                case WEST:
                    west[col][row] = east[newCol][newRow] = false;
                    break;
                }
                generate(newCol, newRow);
            }
        }
    }

    void solve(const int col, const int row) {
        if (isDone || visited[col][row]) return;

        visited[col][row] = true;

        // Draw the current step
        DrawCircle(static_cast<int>((col + 0.5) * cellSize),
                   static_cast<int>((row + 0.5) * cellSize),
                   static_cast<float>(cellSize) / 4, BLUE);
        EndDrawing(); // Ending the drawing forces to display the current state
        BeginDrawing(); // Otherwise it skips the updating frames; maze appears solved for a split second and is reset
        // Middle reached
        if (col == cols / 2 && row == rows / 2) {
            isDone = true;
            return;
        }

        // search each direction in the order shown, given that the wall doesn't exist
        if (!north[col][row]) solve(col, row + 1);
        if (!east[col][row]) solve(col + 1, row);
        if (!south[col][row]) solve(col, row - 1);
        if (!west[col][row]) solve(col - 1, row);

        // If the maze is not finished and the function reaches here,
        // then the cells visited since the last intersection are not part of the solution path
        // These are drawn as gray
        if (!isDone) {
            DrawCircle(static_cast<int>((col + 0.5) * cellSize),
                       static_cast<int>((row + 0.5) * cellSize),
                       static_cast<float>(cellSize) / 4, GRAY);
        }
    }

public:
    Maze(const int cols, const int rows) : cols(cols), rows(rows) {
        init();
        generate(1, 1);
    }

    void draw() {
        ClearBackground(RAYWHITE);
        // Draw the respective line of the cell depending upon the values in the direction vectors
        for (int col = 1; col <= cols; col++) {
            for (int row = 1; row <= rows; row++) {
                if (south[col][row])
                    DrawLine(col * cellSize, row * cellSize, (col + 1) * cellSize, row * cellSize,
                             BLACK);
                if (north[col][row])
                    DrawLine(col * cellSize, (row + 1) * cellSize, (col + 1) * cellSize,
                             (row + 1) * cellSize, BLACK);
                if (west[col][row])
                    DrawLine(col * cellSize, row * cellSize, col * cellSize, (row + 1) * cellSize,
                             BLACK);
                if (east[col][row])
                    DrawLine((col + 1) * cellSize, row * cellSize, (col + 1) * cellSize,
                             (row + 1) * cellSize, BLACK);
            }
        }

        // Center circle
        DrawCircle(static_cast<int>((cols / 2.0 + 0.5) * cellSize),
                   static_cast<int>((rows / 2.0 + 0.5) * cellSize),
                   static_cast<float>(cellSize) / 3, RED);

        // Starting Circle
        DrawCircle(static_cast<int>((1.5) * cellSize),
                   static_cast<int>((1.5) * cellSize),
                   static_cast<float>(cellSize) / 3, RED);
    }

    void solve() {
        std::fill(visited.begin(), visited.end(), std::vector(rows + 2, false));
        isDone = false;
        solve(1, 1); // starting point is (x, y)
    }
};

void waitForSpace() {
    while (!IsKeyPressed(KEY_SPACE)) {
        BeginDrawing();
        DrawText("Press SPACE to continue...", 20, 20, 30, RED);
        EndDrawing();

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Avoid busy-waiting
    }
}

int main() {
    constexpr int cols = 30, rows = 30;
    constexpr int screenWidth = cols * 20 + 40; // 40 is the padding on the right side
    constexpr int screenHeight = rows * 20 + 40; // 40 is the padding on the bottom side

    InitWindow(screenWidth, screenHeight, "Maze Generator and Solver");
    SetTargetFPS(60);

    Maze maze(cols, rows);

    while (!WindowShouldClose()) {
        BeginDrawing();
        maze.draw();
        EndDrawing();
        if (IsKeyPressed(KEY_SPACE)) {
            maze.solve();
            waitForSpace();
        }
        DrawText("Press Space to solve", 0, 0, 20, RED);
    }

    CloseWindow();

    return 0;
}
