#include "game.hpp"
#undef main


int main(int argc, char* argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("Hello",WINDOWPOS,WINDOWPOS,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,0);
    
    OS::window = window;
    OS::renderer = renderer;

    SDL_Texture *t1 = OS::resourceManager.loadTexturePNG("assets/dirt.png");
    SDL_Texture *t2 = OS::resourceManager.loadTexturePNG("assets/grass.png");
    SDL_Texture *t3 = OS::resourceManager.loadTexturePNG("assets/water.png");
    std::cout << "Resoueces: " << OS::resourceManager.textures.size();

    Vector v(200,300);

    Vector mousePosition(0,0);
    
    Vector toward(0,0);
    SDL_Rect move = {0,0,0,0};
    bool isRunning = true;
    while(isRunning){
        OS::Start = SDL_GetTicks64();
        
        while (SDL_PollEvent(&OS::event)){
            if(OS::event.type == SDL_QUIT){
                isRunning = false;
                break;
            }else if(OS::event.type == SDL_KEYDOWN){
                switch (OS::event.key.keysym.sym)
                {
                case SDLK_w:
                    move.y = -1;
                    break;
                case SDLK_s:
                    move.h = 1;
                    break;
                case SDLK_a:
                    move.x = -1;
                    break;
                case SDLK_d:
                    move.w = 1;
                    break;
                default:
                    break;
                }
            }else if(OS::event.type == SDL_KEYUP){
                switch (OS::event.key.keysym.sym)
                {
                case SDLK_w:
                    move.y = 0;
                    break;
                    case SDLK_s:
                    move.h = 0;
                    break;
                case SDLK_a:
                    move.x = 0;
                    break;
                case SDLK_d:
                    move.w = 0;
                    break;
                default:
                    break;
                }
            }else if(OS::event.type == SDL_MOUSEBUTTONDOWN){
                mousePosition = Vector(OS::event.button.x,OS::event.button.y);
            }
        }
        
        toward = Vector(move.x + move.w, move.y + move.h);
        toward = toward.normalize();
        v = v + (toward);

        SDL_Point now = v.toPoint();
        SDL_Rect recta = {now.x,now.y,256,256};
        SDL_Rect rectb = {now.x + 64,now.y-64,128,128};
        SDL_Rect rectc = {now.x + 64,now.y+192,128,128};

        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer,t2,nullptr,&recta);
        SDL_RenderCopy(renderer,t1,nullptr,&rectb);
        SDL_RenderCopy(renderer,t3,nullptr,&rectc);

        // SDL_SetRenderDrawColor(renderer,255,0,0,255);
        // SDL_RenderDrawLine(renderer,v.getIntX(),v.getIntY(),mousePosition.getIntX(),mousePosition.getIntY());
        // SDL_SetRenderDrawColor(renderer,0,255,0,255);
        // SDL_RenderDrawLine(renderer,0,0,mousePosition.getIntX(),mousePosition.getIntY());
        // SDL_SetRenderDrawColor(renderer,0,0,255,255);
        // SDL_RenderDrawLine(renderer,0,0,v.getIntX(),v.getIntY());
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderDrawLine(renderer,v.getIntX(),v.getIntY(),v.getIntX() + toward.getIntX(50),v.getIntY() + toward.getIntY(50));
        
        SDL_RenderPresent(renderer);
        OS::End = SDL_GetTicks64();
        OS::Delta = OS::End - OS::Start;
        if(OS::Delta < DELTA){
            SDL_Delay(DELTA - OS::Delta);
            OS::Delta = DELTA;
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}