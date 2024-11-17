#include "resource_manager.hpp"
#include "os.hpp"

ResourceManager::ResourceManager(){}

ResourceManager::~ResourceManager(){
    for (auto texture = textures.begin(); texture != textures.end(); ++texture){
        if(texture->second)SDL_DestroyTexture(texture->second);
    }
    for (auto font = fonts.begin(); font != fonts.end(); ++font){
        if(font->second)TTF_CloseFont(font->second);
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

TTF_Font *ResourceManager::loadFont(std::string path, int size){
    //加载字体
    if(fonts.find(path) != fonts.end()){
        return fonts[path];
    }
    TTF_Font *font = TTF_OpenFont(path.c_str(), size);
    if (font != nullptr){
        fonts[path] = font;
    }
    return font;
}

void ResourceManager::removeFont(std::string path){
    //判断是否存在 如果存在则删除
    if (fonts.find(path) != fonts.end()){
        TTF_CloseFont(fonts[path]);
        textures.erase(path);
    }
}