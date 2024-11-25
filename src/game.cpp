#include "game.hpp"
// V1代
Game::Game(){}

Game::~Game(){}

Rect rect = {0,0,100,100};


//Test 是用于测试 Object 类的测试类 继承自 Object 类
class Test : public Object{
public:
    Test(ObjectManager *objectManager) : Object(objectManager){}
    ~Test(){}
    void draw(){}
    void update(){}
    void init(){}
    void handleEvent(){
        callback();
    }
    void callback(){
        rect.x += 1;
        rect.y += 1;
    }
    void dispose(){}
};
//——————————————————————————————————————————

void Game::init(){
    if(!OS::window) OS::window = SDL_CreateWindow("test",WINDOWPOS,WINDOWPOS,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if(!OS::renderer) OS::renderer = SDL_CreateRenderer(OS::window,-1,0);

    //测试 资源管理器 加载图片
    OS::resourceManager.loadTexturePNG("assets/grass.png");

    //测试 对象管理器 添加对象
    Test *objecta = new Test(&OS::objectManager);
    objecta->include = 1;
    OS::inputManager.addlistener(objecta);
}

void Game::run(){
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    init();
    loop();
    quit();
    dispose();
    TTF_Quit();
    SDL_Quit();
}

void Game::input(){
    if(OS::event.type == SDL_QUIT){
        isRunning = false;
    }
    //测试 事件管理器 处理事件
    OS::inputManager.handleEvent();
}

void Game::update(){
    //测试 对象管理器 检查对象 并更新对象 并检查对象是否需要删除 并删除对象
    OS::objectManager.check();
    OS::objectManager.update();
}

void Game::render(){
    SDL_SetRenderDrawColor(OS::renderer,bkColor.r,bkColor.g,bkColor.b,bkColor.a);
    SDL_RenderClear(OS::renderer);

    //测试 渲染管理器 渲染对象 渲染图片
    OS::renderManager.drawTexture(OS::resourceManager.loadTexturePNG("assets/grass.png"),&rect);

    SDL_RenderPresent(OS::renderer);
}

void Game::quit(){}

void Game::loop(){
    while(isRunning){
        while (SDL_PollEvent(&OS::event)){
            input();
        }
        update();
        render();
    }
}

// 销毁 释放内存
void Game::dispose(){
    //清除 OS 中的 窗口 渲染器
    OS::Destroy();
    /*
        注： OS 中的 资源管理器 对象管理器 渲染管理器 事件管理器 等 不需要手动销毁
        因为他们的内存不是手动申请的 会在程序结束时自动销毁
    */
}
