#pragma once
#include "common.hpp"
/*

编辑者：初阳LOCW
最新编写时间：2024.11.27

资源管理器 请求文件时未加载则加载，已加载则直接返回
*/

class ResourceManager{
public:
    
    ResourceManager();
    ~ResourceManager();
    //Texture资源
    std::unordered_map<std::string,SDL_Texture *> textures;
    SDL_Texture *loadTextureBMP(std::string path);
    SDL_Texture *loadTexturePNG(std::string path);
    void removeTexture(std::string path);

    //Font资源
    std::unordered_map<std::string,TTF_Font *> fonts;
    TTF_Font *loadFont(std::string path, int size);
    void removeFont(std::string path);
};