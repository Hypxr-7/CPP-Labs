#include <cmath>
#include <raylib.h>

void DrawEquiTriangle(double x, double y, double s);

int main(){
    const int W = 800;
    const int H = 600;

    InitWindow(W, H, "Q8");

    while (!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawEquiTriangle(100, 100, 70);
            DrawEquiTriangle(750, 500, 100);
            DrawEquiTriangle(600, 150, 50);
            DrawEquiTriangle(100, 500, 150);
            DrawEquiTriangle(350, 250, 100);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void DrawEquiTriangle(double x, double y, double s){
    int c = round(s*sqrt(3.0) / 3.0);
    DrawLine(x, y+round(s*sqrt(3.0) / 3.0), x-s/2, y-round(s*sqrt(3.0) / 6.0), RED);
    DrawLine(x, y+round(s*sqrt(3.0) / 3.0), x+s/2, y-round(s*sqrt(3.0) / 6.0), RED);
    DrawLine(x-s/2, y-round(s*sqrt(3.0) / 6.0), x+s/2, y-round(s*sqrt(3.0) / 6.0), RED);
}
