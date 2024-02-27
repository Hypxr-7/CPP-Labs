#include <raylib.h>
#include <iostream>


int main(){
    using namespace std;

    const int W = 600, H = 600;
    int n;

    cout << "Enter Pattern: ";
    cin >> n;

    int size = 600/n;
    
    InitWindow(600, 600, "Raylib");

    while (!WindowShouldClose()) { 

        BeginDrawing();
        
        ClearBackground(BLACK);
        if (n%2 == 0){
            ClearBackground(RED);
            for (int i = 0; i < n; i++){
            int posx = W/double(n) * i;
                for (int j = 0; j < n; j++){
                    int posy = W/double(n) * j;
                    if ((i + j) % 2 ==0 ){
                        DrawRectangle(posx, posy, size, size, BLACK);
                    }
                }
            }
        }
        else{
            ClearBackground(BLACK);
            for (int i = 0; i < n; i++){
                int posx = W/double(n) * i;
                for (int j = 0; j < n; j++){
                    int posy = W/double(n) * j;
                    if ((i + j) % 2 ==0 ){
                        DrawRectangle(posx, posy, size, size, RED);
                    }
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();   
 
    return 0;
}