#pragma once

#include "common.hpp"

/*
作者：初阳LOCW
最新编写时间：2024.11.30
*/

// 信号 用于 事件管理器 处理事件
// 有返回值 无返回值 无参数 有参数

template <typename... Args>
class Signal{
    public:
    std::vector<std::function<void(Args...)>> callbacks;
    void connect(std::function<void(Args...)> callback){
        callbacks.push_back(callback);
    }
    void disconnect(std::function<void(Args...)> callback){
        for (auto it = callbacks.begin(); it!= callbacks.end(); ++it){
            if(*it == callback){
                callbacks.erase(it);
                break;
            }
        }
    }
    void emit(Args... args){
        for (auto callback = callbacks.begin(); callback!= callbacks.end(); ++callback){
            (*callback)(args...);
        }
    }
};