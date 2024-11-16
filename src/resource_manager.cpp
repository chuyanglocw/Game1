#include "resource_manager.hpp"
#include "os.hpp"

ResourceManager::ResourceManager(){}

ResourceManager::~ResourceManager(){
    for (auto texture = textures.begin(); texture != textures.end(); ++texture){
        if(texture->second)SDL_DestroyTexture(texture->second);
    }
}

SDL_Texture *ResourceManager::loadTextureBMP(std::string path){
    //判断是否存在 如果不存在创建 否则直接返回
    if (textures.find(path) != textures.end()){
        return textures[path];
    }
    if (OS::renderer){
        SDL_Surface *surface = SDL_LoadBMP(path.c_str());
        SDL_Texture *texture = SDL_CreateTextureFromSurface(OS::renderer, surface);
        SDL_FreeSurface(surface);
        textures[path] = texture;
        return texture;
    }
    else{
        std::cout << "Renderer not initialized" << std::endl;
        return nullptr;
    }
}

SDL_Texture *ResourceManager::loadTexturePNG(std::string path){
    //判断是否存在 如果不存在创建 否则直接返回
    if (textures.find(path) != textures.end()){
        return textures[path];
    }
    if (OS::renderer){
        IMG_Init(IMG_INIT_PNG);
        SDL_Surface *surface = IMG_Load(path.c_str());
        SDL_Texture *texture = SDL_CreateTextureFromSurface(OS::renderer, surface);
        SDL_FreeSurface(surface);
        textures[path] = texture;
        return texture;
    }
    else{
        std::cout << "Renderer not initialized" << std::endl;
        return nullptr;
    }
}

void ResourceManager::removeTexture(std::string path){
    //判断是否存在 如果存在则删除
    if (textures.find(path) != textures.end()){
        SDL_DestroyTexture(textures[path]);
        textures.erase(path);
    }
}