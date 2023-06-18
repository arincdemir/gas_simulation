#ifndef SIMULATION_H
#define SIMULATION_H

class Simulation
{
private:
    int width;
    int height;
public:
    Simulation(int width, int heigt);
    ~Simulation();
    void update();
    void draw();
};



#endif
