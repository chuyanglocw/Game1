#include "object_manager.hpp"
#include "object.hpp"
ObjectManager::ObjectManager(){}

ObjectManager::~ObjectManager(){
    for (auto object = objects.begin(); object != objects.end(); ++object){
        if(object->second)delete object->second;
    }
}

double ObjectManager::add(Object *object){
    objects[id] = object;
    object->id = id;
    return id++;
}

void ObjectManager::remove(Object *object){
    objects.erase(object->id);
}

Object *ObjectManager::get(double id){
    return objects[id];
}

void ObjectManager::clear(){
    for (auto object = objects.begin(); object != objects.end(); ++object){
        if(object->second)delete object->second;
    }
    objects.clear();
    id = 0;
}

void ObjectManager::update(){
    for (auto object = objects.begin(); object != objects.end(); ++object){
        if(object->second)object->second->update();
    }
}

void ObjectManager::draw(){
    for (auto object = objects.begin(); object != objects.end(); ++object){
        if(object->second)object->second->draw();
    }
}

void ObjectManager::check(){
    for (auto object = objects.begin(); object!= objects.end(); ++object){
        if(object->second->include <= 0)object->second->restTime--;
        if(object->second->restTime < 0)remove(object->second);
    }
}