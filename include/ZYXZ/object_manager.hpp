#pragma once
#include "common.hpp"

/*

编辑者：初阳LOCW
最新编写时间：2024.11.27

管理Object
新建Object并添加进去
通过模板新建Object
*/

class Object;

class ObjectManager{
    public:
    std::unordered_map<double, Object *> objects;
    double id = 0;
    ObjectManager();
    ~ObjectManager();
    double add(Object *object);
    void remove(Object *object);
    Object *get(double id);
    void clear();
    void update();
    void draw();
    void check();
    void print();
};