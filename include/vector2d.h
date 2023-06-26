#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2D
{
public:
    double x;
    double y;
    Vector2D(double x, double y);
    Vector2D();
    ~Vector2D();
    Vector2D operator+(const Vector2D& v);
    Vector2D operator-(const Vector2D& v);
    Vector2D operator*(const double d);
    double getLength();
    void print();
};



#endif
