#include "bricks.hpp"

Bricks::Bricks() {
    padding = 10;
    offset = 50;
    color = GREEN;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            Rectangle rec = {offset + i * 70 + padding, 50 + j * 30 + padding, 60, 20};
            bricks.push_back(rec);
            active.push_back(true);
        }
    }
}

void Bricks::Draw() {
    for (int i = 0; i < bricks.size(); i++) {
        if (active[i]) {
            DrawRectangleRec(bricks[i], color);
        }
    }
}

std::vector<Rectangle> Bricks::GetBricks() {
    return bricks;
}

std::vector<bool> Bricks::GetActive() {
    return active;
}

void Bricks::SetActive(int index, bool value) {
    active[index] = value;
}