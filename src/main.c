#include <SDL2/SDL_render.h>
#include <unistd.h>
#include <stdint.h>
#include<time.h>
#include<stdio.h>
#include "../SDL/include/SDL2/SDL.h"
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>
//#include<SDL2/SDL_image.h>
//#include<SDL2/SDL_ttf.h>

static Uint32 window_Height =1000;
static Uint32 window_Width= 1000;
// static Uint32 cord_x;
// static Uint32 cord_y;
static Uint32 _lasttick;

#define FPS 60
SDL_Renderer *_render ;
void renderer(SDL_Window *win);
SDL_FRect  _playable;



void update_playable(){
_playable.h=(float)window_Height/30;
_playable.w=(float)window_Width /10;
_playable.x=(float)window_Height/30;
_playable.y=(float)window_Width/10;
}


    
void _eventcheck(){
     SDL_DisplayMode dm;
         if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
     SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
     exit(0);
 }
 printf("MAX DWM %d\n",dm.h);
         printf("WINDOW HEIGHT %u \n", window_Height);
         if (window_Height>dm.h*0.8 && window_Width>dm.w*0.8){
             window_Height=dm.h*0.8;
             window_Width=dm.w*0.8;
         }  
        update_playable();
        SDL_SetRenderDrawColor(_render, 250,0,0,255) ;
        SDL_RenderDrawRectF(_render,&_playable);
        SDL_RenderClear(_render);
        SDL_SetRenderDrawColor(_render, 0,255,0,255) ;
        SDL_RenderFillRectF(_render,&_playable);
        SDL_RenderPresent(_render);
}


void renderer(SDL_Window* win){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Event event;
    bool  run=true;
    while(run){
        _eventcheck();
       _lasttick=SDL_GetTicks();
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT){
                run=false;
            }
            else if(event.type==SDL_WINDOWEVENT){
                switch(event.window.event){
                    case SDL_WINDOWEVENT_RESIZED:
                    window_Width=event.window.data1;
                    window_Height=event.window.data2;
                printf("Window resized, new dimensions: %d x %d\n", window_Width, window_Height);

                    SDL_RenderClear(_render);
                    break;
                }
            }
        }
        uint32_t computed=_lasttick+FPS-SDL_GetTicks();
        if (computed>0){
        SDL_Delay(computed);
        }
    }
    SDL_DestroyWindow(win);
    printf("DESTORYED SUCESS");
    SDL_Quit();
    printf("DESTORYED SUCESS 2");
}




int main(){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_DisplayMode dm;
    if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
    SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
    return 1;
}
    SDL_Window *_window=SDL_CreateWindow("GAME" ,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,dm.w*0.8,dm.h*0.8,SDL_WINDOW_RESIZABLE |SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
    _render=SDL_CreateRenderer(_window,0, SDL_RENDERER_ACCELERATED);
    renderer(_window);             
    return 0;
}