#include <iostream>
#include "particle.h"
#include "vector2d.h"
#include "raylib.h"

Particle::Particle(Vector2D position, Vector2D velocity, double mass, double radius, Color color, int id){
    this->position = position;
    this->velocity = velocity;
    this->mass = mass;
    this->radius = radius;
    this->color = color;
    this->id = id;
}

Particle::~Particle(){

}

void Particle::draw(){
    DrawCircle(position.x, position.y, radius, color);
}

void Particle::update(int width, int height) {
    position = position + velocity;
    if (position.x + radius >= width) {
        velocity.x = -velocity.x;
        position.x = width - radius - 1;
    }
    else if (position.x - radius <= 0) {
        velocity.x = -velocity.x;
        position.x = radius + 1;
    }
    if (position.y + radius >= height) {
        velocity.y = -velocity.y;
        position.y = height - radius - 1;
    }
    else if (position.y - radius <= 0) {
        velocity.y = -velocity.y;
        position.y = radius + 1;
    }
}

bool Particle::checkCollision(Particle* p) {
    if ((position - p->position).getLength() <= radius + p->radius)
    {
        processCollision(p);
        return true;
    }
    else
    {
        return false;
    }
}

void Particle::processCollision(Particle* p) {
    double v1x = (mass - p->mass) / (mass + p->mass) * velocity.x + 2 * p->mass / (mass + p->mass) * p->velocity.x;
    double v1y = (mass - p->mass) / (mass + p->mass) * velocity.y + 2 * p->mass / (mass + p->mass) * p->velocity.y;
    double v2x = (p->mass - mass) / (mass + p->mass) * p->velocity.x + 2 * mass / (mass + p->mass) * velocity.x;
    double v2y = (p->mass - mass) / (mass + p->mass) * p->velocity.y + 2 * mass / (mass + p->mass) * velocity.y;

    velocity = Vector2D(v1x, v1y);
    p->velocity = Vector2D(v2x, v2y);

    Vector2D overlap = (position - p->position) * (((radius + p->radius) - (position - p->position).getLength()) / (position - p->position).getLength() / 2);
    position = position + overlap;
    p->position = p->position - overlap;
    return;
}