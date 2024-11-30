#include "game.hpp"


// V1代
Game::Game(){}

Game::~Game(){}

//用于Test cllback 测试
Rect rect = {0,0,100,100};

//Test 是用于测试 Object 类的测试类 继承自 Object 类———————————这些Test相当于对 游戏中的 游戏对象 添加脚本
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

// 用于测试 Triangle 类的测试类 继承自 Object 类 用于测试碰撞检测
class Test2 : public Object{
    public:
    Triangle *triangle;
    Test2(ObjectManager *objectManager) : Object(objectManager){
        triangle = new Triangle(Vector(0,40),Vector(100,0),Vector(0,100));
    }
    ~Test2(){
        delete triangle;
    }
    void draw(){
        SDL_SetRenderDrawColor(OS::renderer,255,0,0,255);
        SDL_RenderDrawLine(OS::renderer,triangle->a.x,triangle->a.y,triangle->b.x,triangle->b.y);
        SDL_RenderDrawLine(OS::renderer,triangle->b.x,triangle->b.y,triangle->c.x,triangle->c.y);
        SDL_RenderDrawLine(OS::renderer,triangle->c.x,triangle->c.y,triangle->a.x,triangle->a.y);
    }
    void update(){}
    void init(){}
    void callback(){
        std::cout << "collide" << std::endl;
    }
    void handleEvent(){
        Vector mousePosition = Vector(OS::event.button.x,OS::OS::event.button.y);
        if (triangle->isCollide(mousePosition)){
            callback();
        }
    }
    void dispose(){}
};



// 用于测试 Polygon 类的测试类 继承自 Object 类 用于测试碰撞检测
class Test3 : public Object{
    public:
    Polygon *polygon;
    Test3(ObjectManager *objectManager) : Object(objectManager){
        polygon = new Polygon();
        polygon->addPoint(Vector(0,0));
        polygon->addPoint(Vector(100,0));
        polygon->addPoint(Vector(100,100));
        polygon->addPoint(Vector(40,100));
        polygon->addPoint(Vector(0,20));
    }
    ~Test3(){
        delete polygon;
    }
    void draw(){
        SDL_SetRenderDrawColor(OS::renderer,0,255,0,255);
        SDL_RenderDrawLine(OS::renderer,polygon->points[0].x,polygon->points[0].y,polygon->points[1].x,polygon->points[1].y);
        SDL_RenderDrawLine(OS::renderer,polygon->points[1].x,polygon->points[1].y,polygon->points[2].x,polygon->points[2].y);
        SDL_RenderDrawLine(OS::renderer,polygon->points[2].x,polygon->points[2].y,polygon->points[3].x,polygon->points[3].y);
        SDL_RenderDrawLine(OS::renderer,polygon->points[3].x,polygon->points[3].y,polygon->points[4].x,polygon->points[4].y);
        SDL_RenderDrawLine(OS::renderer,polygon->points[4].x,polygon->points[4].y,polygon->points[0].x,polygon->points[0].y);
    }
    void update(){}
    void init(){}
    void callback(){
        std::cout << "Polygon collide" << std::endl;
    }
    void handleEvent(){
        Vector mousePosition = Vector(OS::event.button.x,OS::OS::event.button.y);
        if (polygon->isCollide(mousePosition)){
            callback();
        }
    }
    void dispose(){}
};

// 用于测试 Button 类的测试类 继承自 Button 类 用于测试回调函数 用于测试 事件管理器 处理事件
class selfButton : public Button{
    public:
    bool isDown = false;
    Signal<> onDown;
    Signal<> onUp;
    selfButton(SDL_Texture *texture, int x, int y, int w, int h, ObjectManager *objectManager) : Button(texture,x,y,w,h,objectManager){}
    selfButton(ObjectManager *objectManager) : Button(objectManager){}
    ~selfButton(){}
    void handleEvent() override{
        if (OS::event.type == SDL_MOUSEBUTTONDOWN){
            Vector mousePosition = Vector(OS::event.button.x,OS::event.button.y);
            if (box->isCollide(mousePosition)) onDown.emit();
            isDown = true;
        }
        if (isDown && OS::event.type == SDL_MOUSEBUTTONUP){
            onUp.emit();
            isDown = false;
        }
    }
};

class selfSprite : public Sprite{
    public:
    selfSprite(SDL_Texture *texture, int x, int y, int w, int h, ObjectManager *objectManager) : Sprite(texture,x,y,w,h,objectManager){}
    selfSprite(ObjectManager *objectManager) : Sprite(objectManager){}
    ~selfSprite(){}
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
    Test2 *objectb = new Test2(&OS::objectManager);
    objectb->include = 1;
    OS::inputManager.addlistener(objectb);
    Test3 *objectc = new Test3(&OS::objectManager);
    objectc->include = 1;
    OS::inputManager.addlistener(objectc);

    selfSprite *sprite;
    sprite = new selfSprite(OS::resourceManager.loadTexturePNG("assets/frost.png"),400,300,100,100,&OS::objectManager);
    sprite->include = 1;
    OS::inputManager.addlistener(sprite);

    selfButton *button = new selfButton(OS::resourceManager.loadTexturePNG("assets/dirt.png"),300,300,100,100,&OS::objectManager);
    button->include = 1;
    button->onDown.connect([sprite](){
        sprite->flipH = true;
    });
    button->onUp.connect([sprite](){
        sprite->flipH = false;
    });
    OS::inputManager.addlistener(button);

    Signal<bool> signal;
    signal.connect([sprite](bool a){
        sprite->flipH = a;
    });
    signal.emit(true);

}

void Game::run(){
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    init();
    loop();
    quit();
    dispose();
    TTF_Quit();
    OS::objectManager.clear();
    OS::objectManager.print();
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
    OS::objectManager.get(1)->draw();
    OS::objectManager.get(2)->draw();
    OS::objectManager.get(3)->draw();
    OS::objectManager.get(4)->draw();

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
