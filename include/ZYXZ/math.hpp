#pragma once
#include "common.hpp"


namespace cyMath
{
    double min(double a, double b);
    double max(double a, double b);
} // namespace cyMath


class Math{
public:
    static double PI;
    static double E;
    static double RAD;
    static double DEG;
};

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

//TODO： 添加获得法线的方法

//圆形碰撞检测
class Circle{
    public:
    Vector pos;
    double r;
    Circle(Vector pos, double r);
    Circle();
    bool isCollide(Circle &c);
    bool isCollide(Vector &v);
};

//方形碰撞检测
class Box{
    public:
    Vector pos;
    Vector size;
    Box(Vector pos, Vector size);
    Box();
    bool isCollide(Box &box);
    bool isCollide(Vector &v);
};

//三角形碰撞检测
class Triangle{
    public:
    Vector a, b, c;
    Triangle(Vector a, Vector b, Vector c);
    Triangle();
    bool isCollide(Triangle &t);
    bool isCollide(Vector &v);
};

//TODO： 待续完善
//多边形碰撞检测 
class Polygon{
    public:
    std::vector<Vector> points;
    Polygon(std::vector<Vector> points);
    Polygon();
    void addPoint(Vector v);
    void removePoint(Vector v);
    bool isFormedPolygon();
    bool isCollide(Polygon &p);
    bool isCollide(Vector &v);
};