#pragma once

#include "common.hpp"
#include "math.hpp"
#include "os.hpp"
#include "resource_manager.hpp"

class Game{
public:
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