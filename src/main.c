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
// static Uint32 momentum=0 ;
static Uint32 window_Height =0;
static Uint32 window_Width= 0;
static int velocity=0;
static Sint32 cord_x=0;
// static Sint32 velocity=0;
// static Uint32 friction=i-10;
// static Uint32 cord_y;
static Sint32 _lasttick;
const Uint8 *state;
//Ball 
typedef  struct{
   Uint32 ball_x;
   Uint32 ball_y;    
}ball;
ball _ball;


#define FPS 90
SDL_Renderer *_render ;
void renderer(SDL_Window *win);
SDL_FRect  _playable;


void update_playable(void){
_playable.h=(float)window_Height*0.03;
_playable.w=(float)window_Width *0.11;
if (cord_x<5) cord_x=1;
if (cord_x>window_Width-_playable.w-5) cord_x=window_Width-_playable.w;
_playable.x=(float)cord_x;   // only this changes on movable..
_playable.y=(float)window_Height*0.9;
}


void _eventcheck(SDL_Window *win){
    (void )win;
       update_playable();
       _ball.ball_x=10;
       _ball.ball_y=10;
       SDL_SetRenderDrawColor(_render, 0,0,0,255) ;
       SDL_RenderClear(_render);
    //    SDL_SetRenderDrawColor(_render, 255,0,0,255) ;
    //    SDL_RenderClear(_render);
       SDL_SetRenderDrawColor(_render, 0,255,0,255) ;
       SDL_RenderFillRectF(_render,&_playable);
       SDL_RenderDrawPoint(_render,_ball.ball_x,_ball.ball_y);
       SDL_RenderPresent(_render);
}

void renderer(SDL_Window* win){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Event event;
    bool  run=true;
    static float friction=0.99;
    char Prev_key='\0';
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
            }
            printf("states : %d \n",state[SDL_SCANCODE_1]);

            if(state[SDL_SCANCODE_LEFT]){
                velocity-=_playable.w/60;
                }
            if (state[SDL_SCANCODE_RIGHT]){
                velocity+=_playable.w/60;
            }
        velocity*=friction; // Change in velocity 
        cord_x+=velocity; 
        Sint32 computed=_lasttick+1000/FPS-SDL_GetTicks();
        if (computed>0){
        SDL_Delay(computed);
        }
    }
    SDL_DestroyWindow(win);
    printf("DESTORYED SUCESS");
    SDL_Quit();
    printf("DESTORYED SUCESS 2");
}
int main(void){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_DisplayMode dm;
    if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
    SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
    return 1;
}
    state = SDL_GetKeyboardState(NULL);
    SDL_Window *_window=SDL_CreateWindow("GAME" ,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,dm.w*0.8,dm.h*0.8,SDL_WINDOW_RESIZABLE |SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
    _render=SDL_CreateRenderer(_window,0, SDL_RENDERER_ACCELERATED);
    renderer(_window);             
    return 0;
}
