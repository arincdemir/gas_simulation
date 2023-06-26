#include "simulation.h"
#include <stdlib.h>
#include <vector>
#include <iostream>
#include "helpers.h"

using namespace std;

Simulation::Simulation(int width, int height)
{
    this->width = width;
    this->height = height;
    gridCount = 30;
    finalParticleCount = 500;
    frameCount = 0;
    framePerSpawn = 5;
    initialize();
}

Simulation::~Simulation()
{
}

void Simulation::initialize()
{
    grid = vector<vector<vector<Particle*>>>(gridCount + 2, vector<vector<Particle*>>(gridCount + 2));
    srand(1);
    /*
    for (size_t i = 0; i < 1000; i++)
    {
        // int radius = rand() % 20 + 10;
        int radius = 5;
        int mass = radius;
        Vector2D position(radius + randDouble() * (width - 2 * radius), radius + randDouble() * (height - 2 * radius));
        double xVelMultiplier = (rand() % 2 == 0) ? -1 : 1;
        double yVelMultiplier = (rand() % 2 == 0) ? -1 : 1;
        Vector2D velocity((0.3 + randDouble() * 0.5) * xVelMultiplier, (0.3 + randDouble() * 0.5) * yVelMultiplier);
        Color color = Color{255, (unsigned char)(position.x / width * 255), 255, 255};
        Particle*  particle = new Particle(position, velocity, radius, mass, color, i);
        particles.push_back(particle);
        grid = vector<vector<vector<Particle*>>>(gridCount + 2, vector<vector<Particle*>>(gridCount + 2));
    }
    */
}

void Simulation::draw()
{
    for (size_t i = 0; i < particles.size(); i++)
    {
        particles.at(i)->draw();
    }
}

void Simulation::update()
{
    frameCount ++;
    // add a new particle
    if (frameCount % framePerSpawn == 0) {
        for (int i: {-1, 1}) {
            for (int j: {-1, 1}) {
                int radius = 5;
                int mass = radius;
                double x = (i == -1) ? width - radius * 2 : radius * 2;
                double y = (j == -1) ? height - radius * 2 : radius * 2;
                Vector2D position(x, y);
                double xVelMultiplier = i;
                double yVelMultiplier = j;
                Vector2D velocity((1.5 + randDouble() * 0.5) * xVelMultiplier, (1.5 + randDouble() * 0.5) * yVelMultiplier);
                Color color = Color{255, (unsigned char)(position.x / width * 255), 255, 255};
                Particle*  particle = new Particle(position, velocity, radius, mass, color, particles.size());
                particles.push_back(particle);
            }
        }
        
    }

    // move the particles
    for (size_t i = 0; i < particles.size(); i++)
    {
        particles.at(i)->update(width, height);
    }

    // empty the grid
    for (size_t i = 0; i < gridCount + 2; i++)
    {
        for (size_t j = 0; j < gridCount + 2; j++)
        {
            grid[i][j].clear();
        }
    }

    int cellSizeHorizontal = width / gridCount;
    int cellSizeVertical = height / gridCount;
    for (Particle* p : particles)
    {
        int verticalIndex = p->position.y / cellSizeVertical + 1;
        int horizontalIndex = p->position.x / cellSizeHorizontal + 1;
        grid[verticalIndex][horizontalIndex].push_back(p);
    }
    for (size_t i = 1; i < gridCount + 1; i++)
    {
        for (size_t j = 1; j < gridCount + 1; j++)
        {
            vector<Particle*> cell = grid[i][j];
            for (Particle* p : cell)
            {
                for (int x : {-1, 0, 1})
                {
                    for (int y : {-1, 0, 1})
                    {
                        for (Particle* q : grid[i + x][j + y])
                        {
                            if (p->id != q->id) {
                                p->checkCollision(q);
                            }
                        }
                    }
                }
            }
        }
    }
    
}