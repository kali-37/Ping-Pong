#include<stdio.h>
#include "../SDL/include/SDL2/SDL.h"
#include<time.h>
#include<stdbool.h>
//#include<SDL2/SDL_image.h>
//#include<SDL2/SDL_ttf.h>


void _event(SDL_Window* win){
    SDL_Event event;
    bool  run=true;
    while(run){
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT){
                run=false;
            }
        }
    }
    SDL_DestroyWindow(win);
    printf("DESTORYED SUCESS");
    SDL_Quit();
    printf("DESTORYED SUCESS 2");
}



int main(int argc ,char* argv[]){

    printf("argc %d argc %s",argc,*argv);
   if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       1000, 1000, 0);
    
    _event(win);
    return 0;
}

