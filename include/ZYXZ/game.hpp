#pragma once

/*

作者： 初阳LOCW
开始时间： 2024年11月9日
最新更新时间： 2024年11月30日
版本： 0.0 测试阶段

描述： 游戏框架 游戏类
游戏框架
*/

#include "common.hpp"

// 游戏事件
#include "signal.hpp"

// 游戏框架
#include "os.hpp"

// 游戏工具
#include "math.hpp"

// 游戏管理器
#include "resource_manager.hpp"
#include "object_manager.hpp"
#include "render_manager.hpp"
#include "input_manager.hpp"

// 游戏对象
#include "object.hpp"
#include "button.hpp"
#include "sprite.hpp"



/*
新建游戏时 请继承此游戏类 并实现run()方法 并在run()方法中调用init()方法 
并在run()方法中调用loop()方法 并在run()方法最后中调用dispose()方法
*/
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