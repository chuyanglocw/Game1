#pragma once
#include "common.hpp"
/*
资源管理器 请求文件时未加载则加载，已加载则直接返回
*/

class ResourceManager{
public:
    std::unordered_map<std::string,SDL_Texture *> textures;
    ResourceManager();
    ~ResourceManager();
    //Texture资源
    SDL_Texture *loadTextureBMP(std::string path);
    SDL_Texture *loadTexturePNG(std::string path);
    void removeTexture(std::string path);
};