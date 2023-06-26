#include <vector>
#include "particle.h"

#ifndef SIMULATION_H
#define SIMULATION_H

using namespace std;

class Simulation
{
private:
    int width;
    int height;
    int gridCount;
    vector<Particle*> particles;
    vector<vector<vector<Particle*>>> grid;
    int finalParticleCount;
    long long frameCount;
    int framePerSpawn;

    void initialize();
public:
    Simulation(int width, int height);
    ~Simulation();
    void update();
    void draw();
};



#endif
