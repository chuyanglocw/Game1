#pragma once

/*
编辑者：初阳LOCW
最新编写时间：2024.11.30
*/

class ObjectManager;
//TODO: 优化
class Object{
public:
    ObjectManager *objectManager = nullptr;
    double id = -1;
    double include = 0;
    double restTime = 2;
    bool isEnable = false;
    bool isVisible = false;
    //double layer = 0; //图
    double first = 0; //优先更新等级
    Object(ObjectManager *objectManager);
    ~Object();
    virtual void draw(); //Object无显示 但是用于可渲染的子类
    virtual void update();
    virtual void init();
    virtual void handleEvent();
    virtual void callback(); //回调函数
    virtual void dispose(); //释放内存
};