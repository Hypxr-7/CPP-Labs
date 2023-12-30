#include <raylib.h>
#include <cstdlib>
#include <valarray>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;
const int size = 50;

void DrawArray(int arr[]){
    int width = WIDTH / size;
    for (int i = 0; i < size; i++){
        DrawRectangle(i * width, HEIGHT - arr[i] * 10, width, arr[i] * 10, RED);
    }
}

void Draw(int arr[]){
    BeginDrawing();
        ClearBackground(BLUE);
        DrawArray(arr);
    EndDrawing();
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            Draw(arr);
            i++;
        } else {
            arr[k] = R[j];
            Draw(arr);
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        Draw(arr);
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        Draw(arr);
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main(){
    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 50;
    

    InitWindow(WIDTH, HEIGHT, "Sort Display");
    SetTargetFPS(10);
    
    mergeSort(arr, 0, size - 1);

    CloseWindow();

    return 0;
}