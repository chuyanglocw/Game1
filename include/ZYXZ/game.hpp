#pragma once

#include "common.hpp"
#include "os.hpp"
#include "math.hpp"
#include "resource_manager.hpp"
#include "object_manager.hpp"
#include "render_manager.hpp"

class Game{
public:
    Color bkColor = {255,255,255,255};
    bool isRunning = true;
    Game();
    ~Game();
    virtual void run();
    virtual void init();
    virtual void render();
    virtual void loop();
    virtual void update();
    virtual void input();
    virtual void dispose();
    virtual void quit();
};