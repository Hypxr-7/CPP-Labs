#include <raylib.h>
#include <cstdlib>
#include <valarray>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;

    void DrawArray(int arr[], int size){
        int width = WIDTH / size;
        for (int i = 0; i < size; i++){
            DrawRectangle(i * width, HEIGHT - arr[i] * 10, width, arr[i] * 10, RED);
        }
    }

int main(){
    int size = 200;
    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 50;
    

    InitWindow(WIDTH, HEIGHT, "Sort Display");
    SetTargetFPS(10);
    
    while(!WindowShouldClose()){

        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(arr[i], arr[minIndex]);
            }
            BeginDrawing();
                ClearBackground(BLUE);
                DrawArray(arr, size);
            EndDrawing();
        }
    }

    CloseWindow();

    return 0;
}