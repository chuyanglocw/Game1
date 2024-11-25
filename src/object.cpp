#include "object.hpp"
#include "object_manager.hpp"
Object::Object(ObjectManager *objectManager){
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