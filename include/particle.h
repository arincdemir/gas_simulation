#include "vector2d.h"
#include "raylib.h"

#ifndef PARTICLE_H
#define PARTICLE_H

class Particle
{
private:
    double mass;
    double radius;
    Color color;
    void processCollision(Particle* p);
public:
    int id;
    Vector2D position;
    Vector2D velocity;
    Particle(Vector2D position, Vector2D velocity, double mass, double radius, Color color, int id);
    ~Particle();
    void update(int width, int height);
    void draw();
    bool checkCollision(Particle* p);
};



#endif
