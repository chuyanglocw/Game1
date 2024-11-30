#include "object.hpp"
#include "object_manager.hpp"

//添加对 isVisible 和 isEnable 的 初始化
Object::Object(ObjectManager *objectManager){
    isVisible = true;
    isEnable = true;
    this->objectManager = objectManager;
    init();
}

Object::~Object(){
    dispose();
}

void Object::draw(){}

void Object::update(){}

void Object::init(){
    objectManager->add(this);
}


void Object::callback(){}

void Object::handleEvent(){}

void Object::dispose(){}