#include "raylib.h"
#include <complex>

const int WIDTH = 800;
const int HEIGHT = 800;
const int MAX_ITERATIONS = 100;

int main() {
    InitWindow(WIDTH, HEIGHT, "Julia Set");

    Image image = GenImageColor(WIDTH, HEIGHT, BLACK);
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

    std::complex<double> c(-0.8, 0.156);

    // Create an array to hold the pixel data
    Color* pixels = new Color[WIDTH * HEIGHT];

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            std::complex<double> z((x - WIDTH / 2.0) / (WIDTH / 4.0),
                                   (y - HEIGHT / 2.0) / (HEIGHT / 4.0));

            int iterations = 0;
            while (std::abs(z) < 2.0 && iterations < MAX_ITERATIONS) {
                z = z * z + c;
                ++iterations;
            }

            if (iterations == MAX_ITERATIONS) {
                pixels[y * WIDTH + x] = BLACK;
            } else {
                Color color = { (unsigned char)((iterations % 8) * 32), 
                                (unsigned char)((iterations % 16) * 16), 
                                (unsigned char)((iterations % 32) * 8), 
                                255 };
                pixels[y * WIDTH + x] = color;
            }
        }
    }

    // Update the texture with the pixel data
    UpdateTexture(texture, pixels);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(texture, 0, 0, WHITE);
        EndDrawing();
    }

    // Don't forget to delete the pixel data when you're done with it
    delete[] pixels;

    UnloadTexture(texture);
    CloseWindow();

    return 0;
}