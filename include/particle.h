#ifndef PARTICLE_H
#define PARTICLE_H

class Particle
{
private:
    int width;
    int height;
public:
    Particle(int width, int heigt);
    ~Particle();
    void update();
    void draw();
};



#endif
