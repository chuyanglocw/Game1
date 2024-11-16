#include "game.hpp"
// V1代
Game::Game(){}

Game::~Game(){}

void Game::init(){
    if(!OS::window) OS::window = SDL_CreateWindow("test",WINDOWPOS,WINDOWPOS,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if(!OS::renderer) OS::renderer = SDL_CreateRenderer(OS::window,-1,0);
}

void Game::run(){
    SDL_Init(SDL_INIT_EVERYTHING);
    init();
    loop();
    quit();
    dispose();
    SDL_Quit();
}

void Game::input(){
    if(OS::event.type == SDL_QUIT){
        isRunning = false;
    }
}

void Game::update(){}

void Game::render(){
    SDL_SetRenderDrawColor(OS::renderer,bkColor.r,bkColor.g,bkColor.b,bkColor.a);
    SDL_RenderClear(OS::renderer);
    SDL_RenderPresent(OS::renderer);
}

void Game::quit(){}

void Game::loop(){
    while(isRunning){
        while (SDL_PollEvent(&OS::event)){
            input();
        }
        update();
        render();
    }
}

void Game::dispose(){
    OS::Destroy();
}
