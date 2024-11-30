#pragma once

#include "common.hpp"

/*
编辑者：初阳LOCW
最新编写时间：2024.11.30
*/

//TODO: 添加 isEnable 变量  用于控制是否启用该对象 并 在事件处理应用该变量判断

class Box;

class Vector;

class Object;

class ObjectManager;

template <typename... Args>
class Signal;

class Button : public Object{
    public:
    bool isEnable = true;
    SDL_Texture *texture = nullptr;
    Box *box = nullptr;
    bool isDown = false;
    Signal<> onDown;
    Signal<> onUp;
    Button(SDL_Texture *texture, int x, int y, int w, int h, ObjectManager *objectManager);
    Button(ObjectManager *objectManager);
    ~Button();
    void init();
    void draw();
    void update();
    void setTexture(SDL_Texture *texture);
    void setSize(Vector size);
    void setPos(Vector pos);
    void handleEvent();
    void callback();
    void dispose();
};