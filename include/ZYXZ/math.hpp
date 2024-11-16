#pragma once
#include "common.hpp"
class Vector{
    public:
    float x, y;
    Vector(float x, float y);
    Vector(const Vector &v);
    Vector();
    Vector operator+(const Vector& v);
    Vector operator-(const Vector& v);
    Vector operator*(const double& d);
    Vector operator/(const double& d);
    double operator*(const Vector& v);
    Vector operator^(const Vector& v);
    double length();
    double length2();
    double distanceTo(Vector &v);
    double distanceTo2(Vector &v);
    Vector normalize();
    Vector rotate(double angle);
    Vector rotate90();
    Vector rotate180();
    SDL_Point toPoint();
    Vector toInt();
    double angle();
    int getIntX(const float &ex = 1);
    int getIntY(const float &ex = 1);
};

class Math{
public:
    static double PI;
    static double E;
    static double RAD;
    static double DEG;
};