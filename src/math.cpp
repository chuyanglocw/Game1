#include "math.hpp"



inline double cyMath::min(double a, double b){
    return a < b ? a : b;
}
inline double cyMath::max(double a, double b){
    return a > b ? a : b;
}


double Math::PI = 3.1415926;
double Math::E = 2.71828;
double Math::RAD = Math::PI / 180.0;
double Math::DEG = 180.0 / Math::PI;


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

//Circle
Circle::Circle(){
    pos.x = 0;
    pos.y = 0;
    r = 0;
}
Circle::Circle(Vector pos, double r){
    this->pos.x = pos.x;
    this->pos.y = pos.y;
    this->r = r;
}

bool Circle::isCollide(Circle &c){
    return pos.distanceTo2(c.pos) <= (r + c.r) * (r + c.r);
}

bool Circle::isCollide(Vector &v){
    return pos.distanceTo2(v) <= r * r;
}

//Box
Box::Box(){
    pos.x = 0;
    pos.y = 0;
    size.x = 0;
    size.y = 0;
}

Box::Box(Vector pos, Vector size){
    this->pos.x = pos.x;
    this->pos.y = pos.y;
    this->size.x = size.x;
    this->size.y = size.y;
}

bool Box::isCollide(Box &box){
    return cyMath::max(pos.x, box.pos.x) <= cyMath::min(pos.x + size.x, box.pos.x + box.size.x) && cyMath::max(pos.y, box.pos.y) <= cyMath::min(pos.y + size.y, box.pos.y + box.size.y);
}

bool Box::isCollide(Vector &v){
    return cyMath::max(pos.x, v.x) <= cyMath::min(pos.x + size.x, v.x) && cyMath::max(pos.y, v.y) <= cyMath::min(pos.y + size.y, v.y);
}

//triangle
Triangle::Triangle(){
    a.x = 0;
    a.y = 0;
    b.x = 0;
    b.y = 0;
    c.x = 0;
    c.y = 0;
}
Triangle::Triangle(Vector a, Vector b, Vector c){
    this->a.x = a.x;
    this->a.y = a.y;
    this->b.x = b.x;
    this->b.y = b.y;
    this->c.x = c.x;
    this->c.y = c.y;
}
bool Triangle::isCollide(Triangle &t){
    return isCollide(t.a) || isCollide(t.b) || isCollide(t.c);
}

bool Triangle::isCollide(Vector &v){
    // 计算向量 v0，v1，v2
    Vector v0 = v - a;
    Vector v1 = b - a;
    Vector v2 = c - a;
    // 计算向量的点积
    double dot00 = v1 * v1;
    double dot01 = v1 * v2;
    double dot02 = v1 * v0;
    double dot11 = v2 * v2;
    double dot12 = v2 * v0;
    // 计算分母的倒数
    double inverDeno = 1 / (dot00 * dot11 - dot01 * dot01);
    // 计算 u 和 v
    double u = (dot11 * dot02 - dot01 * dot12) * inverDeno;
    double va = (dot00 * dot12 - dot01 * dot02) * inverDeno;
    // 判断点是否在三角形内部
    return (u >= 0) && (va >= 0) && (u + va < 1);
}

//TODO: 待优化 以三角形 优化 Polygon 判断是否相交
//Polygon
Polygon::Polygon(){}

Polygon::Polygon(std::vector<Vector> points){
    this->points = points;
}


void Polygon::addPoint(Vector v){
    points.push_back(v);
}

void Polygon::removePoint(Vector v){
    for (auto point = points.begin(); point!= points.end(); ++point){
        if(point->x == v.x && point->y == v.y){
            points.erase(point);
            break;
        }
    }
}

//Polygon 中的点 法判断是否相交
bool Polygon::isCollide(Polygon &p){
    bool flag = false;
    for (auto point = points.begin(); point!= points.end(); ++point){
        if(p.isCollide(*point)){
            flag = true;
            break;
        }
    }
    return flag;
}

//射线法判断是否相交
bool Polygon::isCollide(Vector &v){
    int crossingCount = 0;
    auto point = points.begin();
    for (; point != points.end(); ++point) {
        auto nextPoint = (point + 1 == points.end()) ? points.begin() : point + 1;
        Vector p1 = *point;
        Vector p2 = *nextPoint;

        // 跳过水平线段和不与向量y坐标相交的线段
        if (p1.y == p2.y || v.y < cyMath::min(p1.y, p2.y) || v.y >= cyMath::max(p1.y, p2.y)) continue;

        double x = (v.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;
        if (x > v.x) crossingCount++;
    }
    return crossingCount % 2 == 1;
}