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

static Uint32 window_Height =0;
static Uint32 window_Width= 0;
static Sint32 cord_x=0;
// static Uint32 cord_y;
static Sint32 _lasttick;

#define FPS 90
SDL_Renderer *_render ;
void renderer(SDL_Window *win);
SDL_FRect  _playable;






void update_playable(){
_playable.h=(float)window_Height*0.03;
_playable.w=(float)window_Width *0.11;
printf("%d   \n",cord_x);
if (cord_x<0) cord_x=1;
if (cord_x>window_Width-_playable.w) cord_x=window_Width-_playable.w;
_playable.x=(float)cord_x;   // only this changes on movable..
// if (0<_playable.x<window_Width){

// }
_playable.y=(float)window_Height*0.9;
}




    
void _eventcheck(SDL_Window *win){
    SDL_DisplayMode dm;
    if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
    SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
    exit(0);
}
        if (window_Height<dm.h*0.8 && window_Width<dm.w*0.8){
            window_Height=dm.w*0.8;
            window_Width=dm.h*0.9;
            SDL_SetWindowSize(win,window_Height,window_Width);
        }
       update_playable();
       SDL_RenderClear(_render);
       SDL_SetRenderDrawColor(_render, 0,0,0,255) ;
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
       _lasttick=SDL_GetTicks();
        _eventcheck(win);
        SDL_RenderPresent(_render);
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT){
                run=false;
            }
            else if(event.type==SDL_WINDOWEVENT){
                switch(event.window.event){
                    case SDL_WINDOWEVENT_RESIZED:
                    window_Width=event.window.data1;
                    window_Height=event.window.data2;

                    SDL_RenderClear(_render);
                    break;
                }
            }
            else if(event.type==SDL_KEYDOWN){
                switch(event.key.keysym.sym){
                   case SDLK_LEFT :
                   cord_x-=55;
                   break;
                   case SDLK_RIGHT:
                   cord_x+=55;
                   break; 
                }
                }

            }
        Sint32 computed=_lasttick+1000/FPS-SDL_GetTicks();
        printf("COMPUTED ,%d",computed);
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