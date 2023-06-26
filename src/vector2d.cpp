#include "vector2d.h"
#include <iostream>
#include <cmath>

Vector2D::Vector2D(double x, double y){
    this->x = x;
    this->y = y;
}

Vector2D::Vector2D(){
    x = 0;
    y = 0;
}

Vector2D::~Vector2D(){

}

Vector2D Vector2D::operator+(const Vector2D& v){
    return Vector2D(x + v.x, y + v.y);
}

Vector2D Vector2D::operator-(const Vector2D& v){
    return Vector2D(x - v.x, y - v.y);
}

Vector2D Vector2D::operator*(double d){
    return Vector2D(x * d, y * d);
}

double Vector2D::getLength() {
    return sqrt(x * x + y * y);
}

void Vector2D::print(){
    std::cout << "(" << x << ", " << y << ")";
}