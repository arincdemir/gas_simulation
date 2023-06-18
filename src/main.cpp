#include "raylib.h"
#include "vector2d.h"

int main() {
    
    InitWindow(600, 600, "Gas Simulation");
    SetTargetFPS(144);
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    
}