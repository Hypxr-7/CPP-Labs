#pragma once

#include <raylib.h>
#include <vector> 

class Bricks {
private:
    std::vector<Rectangle> bricks;
    std::vector<bool> active;
    Color color;
    int padding;
    int offset;
public:
    Bricks();
    void Draw();
    std::vector<Rectangle> GetBricks();
    std::vector<bool> GetActive();
    void SetActive(int index, bool value);
};