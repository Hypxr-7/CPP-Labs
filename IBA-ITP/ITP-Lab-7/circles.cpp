#include <raylib.h>
#include <iostream>
#include <cstdlib>

int main(){
    using namespace std;
    
    srand(time(0));

    int maxCircles, minRad, maxRad;
    double blackChance;
    cout << "Max Circles: ";
    cin >> maxCircles;
    cout << "Percentage Black(0 to 1): ";
    cin >> blackChance;
    cout << "Min Radius (ideally more than 5): ";
    cin >> minRad; 
    cout << "Max Radius: ";
    cin >> maxRad;

    int yCoord[maxCircles] = {};
    int xCoord[maxCircles] = {};
    double random[maxCircles] = {};
    double radius[maxCircles] = {};

    for (int i = 0; i < maxCircles; i++){
        xCoord[i] = rand()%600;
        yCoord[i] = rand()%600;
        random[i] = rand()/double(RAND_MAX);
        radius[i] = rand() % (maxRad-minRad) + minRad;
    }
    
    InitWindow(600, 600, "Raylib");

    while (!WindowShouldClose()) { 

    
        ClearBackground(RAYWHITE);

        for (int i = 0; i < maxCircles; i++){

            if (random[i] < blackChance){
                DrawCircle(xCoord[i], yCoord[i], radius[i], BLACK);
            }
            else{
                DrawCircle(xCoord[i], yCoord[i], radius[i], RED); // used red instead of white for better visibility
            }


        }

        EndDrawing();
    }

    CloseWindow();   
 
    return 0;
}