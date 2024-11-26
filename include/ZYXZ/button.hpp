#pragma once

#include "common.hpp"


class Box;

class Vector;

class Object;

class ObjectManager;

class Button : public Object{
    public:
    SDL_Texture *texture = nullptr;
    Box *box = nullptr;
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