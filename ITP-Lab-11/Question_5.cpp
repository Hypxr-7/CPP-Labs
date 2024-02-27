#include <cmath>   
#include "raylib.h" 

const int W = 800, H = 800; 

void draw(int n, double sz, double x, double y) {
    if(n==0) return;
    double x0 = x - sz/2, x1 = x + sz/2;
    double y0 = y - sz/2, y1 = y + sz/2;
    

    DrawRectangle(x0*W, y0*H, sz*W, sz*H, GRAY);
    DrawRectangleLines(x0*W, y0*H, sz*W, sz*H, BLACK);
    // DrawLine(x0*W, y*H,  x1*W, y*H,  WHITE);
    // DrawLine(x0*W, y0*H, x0*W, y1*H, WHITE);
    // DrawLine(x1*W, y0*H, x1*W, y1*H, WHITE);

    draw(n-1, sz/2.2, x0, y0);
    draw(n-1, sz/2.2, x0, y1);
    draw(n-1, sz/2.2, x1, y0);
    draw(n-1, sz/2.2, x1, y1);
}

int main()
{
    // init windows of W width and H height
    InitWindow(W, H, "Square Tree"); 

    // Main game loop
    while (!WindowShouldClose()) {   // Detect window close button or ESC key
        // Draw
        BeginDrawing();
            draw(6, .5, .5, .5);
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context
 
    return 0;
}