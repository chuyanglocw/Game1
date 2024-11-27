#pragma once

#include "common.hpp"

/*


编辑者：初阳LOCW
最新编写时间：2024.11.27


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
    void addlistener(Object *object);
    void removelistener(Object *object);
    void handleEvent();
};