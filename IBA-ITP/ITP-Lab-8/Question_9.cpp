#include<iostream>
#include<cmath>
#include "raylib.h"

double eval(double t, int k);

int main()
{
    const int W=800, H=600;
    const double pi=3.1415927; 
    const double xmin=0, xmax=2*pi, ymin=-2, ymax=2; 
    const int N = 200; 
    int x[N+1], y[N+1];
    int k; 
    std::cout << "Enter Value of k: ";
    std::cin >> k;

    for(int i=0; i<=N; i++) {
        double px = i*2*pi/N;
        double py = eval(px, k);
        x[i] = round((px-xmin)/(xmax-xmin) * W);
        y[i] = round((py-ymin)/(ymax-ymin) * H);
    }


    InitWindow(W, H, "Plot function"); 

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(WHITE);
            for(int i=0; i<N; i++)
                DrawLine(x[i], y[i], x[i+1], y[i+1], BLUE);

        EndDrawing();
    }

    CloseWindow();   
 
    return 0;
}

double eval(double t, int k){
    double num = 0;
    for (double i = 1; i <= k; i++){
        num += sin(i*t)/i;
    }

    return 2.0/3.1415927 * num;
}