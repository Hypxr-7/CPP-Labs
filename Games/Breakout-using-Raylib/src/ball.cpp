#include "ball.hpp"

Ball::Ball() {
    position = {400, 225};
    speed = {5, 5};
    radius = 10;
    color = RED;
}

void Ball::Update() {
    position.x += speed.x;
    position.y += speed.y;

    if (position.x + radius >= GetScreenWidth() || position.x - radius <= 0) {
        speed.x *= -1;
    }

    if (position.y + radius >= GetScreenHeight() || position.y - radius <= 0) {
        speed.y *= -1;
    }
}

void Ball::Draw() {
    DrawCircleV(position, radius, color);
}

Vector2 Ball::GetPosition() {
    return position;
}

float Ball::GetRadius() {
    return radius;
}

void Ball::SetSpeed(Vector2 newSpeed) {
    speed = newSpeed;
}

Vector2 Ball::GetSpeed() {
    return speed;
}