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
    int size = 20;
    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 50;
    

    InitWindow(WIDTH, HEIGHT, "Sort Display");
    SetTargetFPS(10);
    

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                BeginDrawing();
                    ClearBackground(BLUE);
                    DrawArray(arr, size);
                EndDrawing();
            }
        }
    }
    

    CloseWindow();

    return 0;
}