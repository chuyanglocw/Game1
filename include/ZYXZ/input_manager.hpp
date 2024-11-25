#pragma once

#include "common.hpp"

/*
管理Input
新建Input并添加进去
通过模板新建Input
*/

class Object;

class InputManager{
    public:
    InputManager();
    ~InputManager();
    std::vector<Object *> objects;
    void addlisener(Object *object);
    void removelisener(Object *object);
    void handleEvent();
};