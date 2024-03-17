#pragma once

#include <raylib.h>

class Ball {
private:
    Vector2 position;
    Vector2 speed;
    float radius;
    Color color;
public:
    Ball();
    void Update();
    void Draw();
    Vector2 GetPosition();
    float GetRadius();
    void SetSpeed(Vector2 newSpeed);
    Vector2 GetSpeed();
    

};
