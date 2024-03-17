#pragma once

#include <raylib.h>

class Paddle {
private:
    Vector2 position;
    Vector2 size;
    int speed;
    Color color;
public:
    Paddle();
    void Update();
    void Draw();
    Rectangle GetPad();
};