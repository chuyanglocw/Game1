#include "os.hpp"
#include "object.hpp"
#include "object_manager.hpp"
#include "math.hpp"
#include "button.hpp"

Button::Button(SDL_Texture *texture,int x, int y, int w, int h, ObjectManager *objectManager) : Object(objectManager){
    this->texture = texture;
    this->box = new Box();
    this->box->size = Vector(w, h);
    this->box->pos = Vector(x, y);
}
Button::Button(ObjectManager *objectManager) : Object(objectManager){
    this->texture = nullptr;
    this->box = nullptr;
}

Button::~Button(){
    dispose();
}
void Button::init(){
    objectManager->add(this);
}

void Button::draw(){
    SDL_Rect rect = {box->pos.getIntX(), box->pos.getIntY(), box->size.getIntX(), box->size.getIntY()};
    SDL_RenderCopy(OS::renderer, texture, NULL, &rect);
}

void Button::update(){}

void Button::setSize(Vector size){
    if(box){
        box = new Box();
    }
    box->size = size;
}

void Button::setPos(Vector pos){
    if(box){
        box = new Box();
    }
    box->pos = pos;
}

void Button::setTexture(SDL_Texture *texture){
    this->texture = texture;
}

void Button::handleEvent(){
    if(box && OS::event.type == SDL_MOUSEBUTTONDOWN){
        Vector mousePos = Vector(OS::event.button.x, OS::event.button.y);
        if(box->isCollide(mousePos)){
            callback();
        }
    }
}

void Button::callback(){}

void Button::dispose(){
    delete box;
}