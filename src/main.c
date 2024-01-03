#include "../include/main.h"
#include "../include/_ball.h"
Ball _ball;
const Uint8 *state;
SDL_Renderer *_render ;
SDL_FRect  _playable;


void update_playable(void){
_playable.h=(float)window_Height*0.03;
_playable.w=(float)window_Width *0.11;
if (cord_x<0) cord_x=1;
if (cord_x+_playable.w>window_Width) cord_x=window_Width-_playable.w;
_playable.x=(float)cord_x;   // only this changes on movable..
_playable.y=(float)window_Height*0.9;
printf("CORD X AND CORD Y %d and %d    %d  %d \n",cord_x,cord_x,window_Height,window_Width);
}


void _eventcheck(SDL_Window *win){
    (void )win;
       update_playable();
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
    static float friction=0.9;
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

            if(state[SDL_SCANCODE_LEFT]){
                velocity-=_playable.w/80;
                }
            if (state[SDL_SCANCODE_RIGHT]){
                velocity+=_playable.w/80;
                // printf("states  RIGHT : %d \n",state[SDL_SCANCODE_RIGHT]);
            }
        velocity*=friction; // Change in velocity 
        printf("VELOCITY %f \n ",velocity);
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
