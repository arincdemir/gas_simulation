#include "raylib.h"
#include "simulation.h"
#include <iostream>
#include <chrono>

int main() {
    
    int width = 600;
    int height = 600;
    InitWindow(width, height, "Gas Simulation");
    SetTargetFPS(60);

    Simulation sim(width, height);
    
    while (!WindowShouldClose())
    {
        std::cout << GetFPS() << std::endl;
        BeginDrawing();
        ClearBackground(BLACK);
        sim.update();
        sim.draw();
        EndDrawing();
    }
    
}