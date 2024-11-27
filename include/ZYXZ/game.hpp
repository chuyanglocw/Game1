#pragma once

/*

作者： 初阳LOCW
开始时间： 2024年11月9日
最新更新时间： 2024年11月25日
版本： 0.0 测试阶段

描述： 游戏框架 游戏类
游戏框架
*/

#include "common.hpp"
#include "os.hpp"
#include "math.hpp"
#include "resource_manager.hpp"
#include "object_manager.hpp"
#include "render_manager.hpp"
#include "input_manager.hpp"
#include "object.hpp"
#include "button.hpp"
#include "sprite.hpp"


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