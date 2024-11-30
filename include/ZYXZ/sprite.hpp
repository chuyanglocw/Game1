#pragma once

/*
编辑者：初阳LOCW
最新编写时间：2024.11.30
*/

//TODO： 添加精灵的其他功能 和 适配 Altlas 贴图

#include "common.hpp"

class Vector;

class Box;

class Object;

class ObjectManager;

class Sprite : public Object{
    public:
    SDL_Texture *texture = nullptr;
    Box *box = nullptr;
    bool flipH = false;
    bool flipV = false;
    double angle = 0;
    Sprite(SDL_Texture *texture, int x, int y, int w, int h, ObjectManager *objectManager);
    Sprite(ObjectManager *objectManager);
    ~Sprite();
    void init();
    void draw();
    void update();
    void handleEvent();
    void callback();
    void setTexture(SDL_Texture *texture);
    void setSize(Vector size);
    void setPos(Vector pos);
    void setAngle(double angle);
    void rotate(double angle);
    void dispose();
};