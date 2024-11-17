#include "os.hpp"
#include "resource_manager.hpp"
#include "object_manager.hpp"
#include "render_manager.hpp"

Uint64 OS::Start = 0;
Uint64 OS::End = 0;
Uint64 OS::Delta = 0;

SDL_Window *OS::window = nullptr;
SDL_Renderer *OS::renderer = nullptr;
SDL_Event OS::event;
ResourceManager OS::resourceManager;
ObjectManager OS::objectManager;
RenderManager OS::renderManager;

void OS::Destroy(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}