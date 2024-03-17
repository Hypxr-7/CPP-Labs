#include "paddle.hpp"

Paddle::Paddle() {
    position = {400, 400};
    speed = 10;
    size = {100, 20};
    color = RED;
}

void Paddle::Update() {
    if (IsKeyDown(KEY_RIGHT)) {
        position.x += speed;
    }
    if (IsKeyDown(KEY_LEFT)) {
        position.x -= speed;
    }
    if (position.x + size.x >= GetScreenWidth()) {
        position.x = GetScreenWidth() - size.x;
    }
    if (position.x <= 0) {
        position.x = 0;
    }
}

void Paddle::Draw() {
    DrawRectangleV(position, size, color);
}

Rectangle Paddle::GetPad() {
    return {position.x, position.y, size.x, size.y};
}