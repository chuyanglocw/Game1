#pragma once
#define OS_FEATURE "WINDOWS"
#include "common.hpp"

/*
应用基本信息

OS保存应用 window renderer event 等信息为其他文件公用
*/

#define FPS 60
#define DELTA (1000 / FPS)
#define WINDOWPOS SDL_WINDOWPOS_CENTERED

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 800

class ResourceManager;
class ObjectManager;

class OS{
public:
    static Uint64 Start, End, Delta;
    static SDL_Window *window;
    static SDL_Renderer *renderer;
    static SDL_Event event;
    static ResourceManager resourceManager;
    static ObjectManager objectManager;
};