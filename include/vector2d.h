#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2D
{
private:
    double x;
    double y;
public:
    Vector2D(double x, double y);
    ~Vector2D();
    Vector2D operator+(const Vector2D& v);
    Vector2D operator-(const Vector2D& v);
    Vector2D operator*(const double d);
    void print();
};



#endif
