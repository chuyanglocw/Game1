#include "math.hpp"
#include "object.hpp"
#include "object_manager.hpp"
#include "render_manager.hpp"
#include "os.hpp"
#include "sprite.hpp"

Sprite::Sprite(SDL_Texture *texture, int x, int y, int w, int h, ObjectManager *objectManager) : Object(objectManager){
    this->texture = texture;
    this->box = new Box();
    this->box->pos = Vector(x,y);
    this->box->size = Vector(w,h);
}

Sprite::Sprite(ObjectManager *objectManager) : Object(objectManager){
    this->box = new Box();
}

Sprite::~Sprite(){
    dispose();
}

void Sprite::init(){
    objectManager->add(this);
}

//删除 isvisible 判断。可见性由 渲染管理器 控制 渲染管理器 会在渲染时 遍历所有对象 并调用 draw 函数 并将其绘制到屏幕上
void Sprite::draw(){

    SDL_RendererFlip flip = SDL_FLIP_NONE;
    if (flipH && flipV){
        flip = (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
    }else if (flipH){
        flip = SDL_FLIP_HORIZONTAL;
    }else if (flipV){
        flip = SDL_FLIP_VERTICAL;
    }
    Point center = {0,0};
    Rect dstRect = {box->pos.getIntX(),box->pos.getIntY(),box->size.getIntX(),box->size.getIntY()};
    OS::renderManager.drawTexture(texture,NULL,&dstRect,angle,&center,flip);

}

void Sprite::update(){}

void Sprite::handleEvent(){}

void Sprite::callback(){}

void Sprite::dispose(){
    delete box;
}

void Sprite::setTexture(SDL_Texture *texture){
    texture = texture;
}

void Sprite::setSize(Vector size){
    box->size = size;
}

void Sprite::setPos(Vector pos){
    box->pos = pos;
}

void Sprite::setAngle(double angle){
    angle = angle;
}

void Sprite::rotate(double angle){
    angle += angle;
}

