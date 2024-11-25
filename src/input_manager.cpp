#include "input_manager.hpp"



#include "object.hpp"
#include "os.hpp"


InputManager::InputManager(){}

InputManager::~InputManager(){}

void InputManager::addlistener(Object *object){
    objects.push_back(object);
}


void InputManager::removelistener(Object *object){
    for (int i = 0; i < objects.size(); i++) {
        if (objects[i] == object) {
            // 交换当前元素与最后一个元素
            if (i != objects.size() - 1) {
                objects[i] = objects.back();
            }
            // 删除最后一个元素
            objects.pop_back();
            return;
        }
    }
}

void InputManager::handleEvent(){

    for(int i = 0; i < objects.size(); i++){
        objects[i]->handleEvent();
    }

}