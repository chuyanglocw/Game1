#include "math.hpp"

Vector::Vector(){
    x = 0;
    y = 0;
}

Vector::Vector(float x, float y){
    this->x = x;
    this->y = y;
}

Vector::Vector(const Vector &v){
    x = v.x;
    y = v.y;
}

Vector Vector::operator+(const Vector& v){
    return Vector(x + v.x, y + v.y);
}

Vector Vector::operator-(const Vector& v){
    return Vector(x - v.x, y - v.y);
}

Vector Vector::operator*(const double& d){
    return Vector(x * d, y * d);
}

Vector Vector::operator/(const double& d){
    return Vector(x / d, y / d);
}

double Vector::operator*(const Vector& v){
    return x * v.x + y * v.y;
}

Vector Vector::operator^(const Vector& v){
    return Vector(x * v.y - y * v.x, y * v.x - x * v.y);
}

double Vector::length(){
    return sqrt(x * x + y * y);
}

double Vector::length2(){
    return x * x + y * y;
}

double Vector::distanceTo(Vector &v){
    return sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y));
}

double Vector::distanceTo2(Vector &v){
    return (x - v.x) * (x - v.x) + (y - v.y) * (y - v.y);
}

Vector Vector::normalize(){
    double len = length();
    if (len)
    {
        return Vector(x / len, y / len);
    }else{
        return Vector(0, 0);
    }
}

Vector Vector::rotate(double angle){
    return Vector(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));
}

Vector Vector::rotate90(){
    return Vector(-y, x);
}

Vector Vector::rotate180(){
    return Vector(-x, -y);
}

SDL_Point Vector::toPoint(){
    return {(int)x, (int)y};
}

Vector Vector::toInt(){
    return Vector((int)x, (int)y);
}

double Vector::angle() {
    return atan2(y, x);
}

int Vector::getIntX(const float &ex){
    return (int)(x * ex);
}

int Vector::getIntY(const float &ex){
    return (int)(y * ex);
}

double Math::PI = 3.1415926;
double Math::E = 2.71828;
double Math::RAD = Math::PI / 180.0;
double Math::DEG = 180.0 / Math::PI;
