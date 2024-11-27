#pragma once
#define OS_FEATURE 1
#include "common.hpp"

/*


编辑者：初阳LOCW
最新编写时间：2024.11.27


OS_FEATURE: 1:windows 2:android

应用基本信息

OS保存应用 window renderer event 等信息为其他文件公用
*/


typedef SDL_Point Point;
typedef SDL_Rect Rect;
typedef SDL_Color Color;
typedef SDL_Surface Surface;
typedef SDL_Texture Texture;

#define FPS 60
#define DELTA (1000 / FPS)
#define WINDOWPOS SDL_WINDOWPOS_CENTERED

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 800

class ResourceManager;
class ObjectManager;
class RenderManager;
class InputManager;

class OS{
public:
    static Uint64 Start, End, Delta;
    static SDL_Window *window;
    static SDL_Renderer *renderer;
    static SDL_Event event;
    static ResourceManager resourceManager;
    static ObjectManager objectManager;
    static RenderManager renderManager;
    static InputManager inputManager;
    static void Destroy();
};