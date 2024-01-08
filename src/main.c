#include "../include/main.h"
#include "../include/_ball.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define M_PI3 3.1415

SDL_FRect _playable; 
Ball *_ball;
const Uint8 *state;
SDL_Renderer *_render ;
void ball_direction(Ball *_ball){
    _ball->radius=_playable.h/2;
    _ball->x+=_ball->vx;
    _ball->y+=_ball->vy;
    if (_ball->x<=0 || _ball->x+_ball->radius*2 >=window_Width) _ball->vx*=-1 ;
    if (_ball->y<=0  ) _ball->vy*=-1; 
    SDL_FPoint point[4];
    point[0].x=_ball->x;
    point[0].y=_ball->y+_ball->radius; 
    point[1].x=_ball->x+_ball->radius;
    point[1].y=_ball->y;
    point[2].x=_ball->x-_ball->radius;
    point[2].y=_ball->y;
    point[3].x=_ball->x;
    point[3].y=_ball->y-_ball->radius; 

    Uint32 _half_loc_playable=_playable.x+_playable.w/2;

                      
    if (SDL_PointInFRect(&point[0],&_playable) || SDL_PointInFRect(&point[1],&_playable) || SDL_PointInFRect(&point[2],&_playable) || SDL_PointInFRect(&point[3],&_playable)){
        _ball->vy*=-1;
        _ball->y-=_ball->radius*3;
    }

    bool Break=false;
    if (_size_file!=UINT32_MAX && Block[0][0]!=NULL){
        

    Uint32 count1=0;
    while(count1<_size_file){
        Uint32 count2=0;
        while(count2<_size_lines){
            if (SDL_PointInFRect(&point[0],&Block[count1][count2]->block)||SDL_PointInFRect(&point[1],&Block[count1][count2]->block)||SDL_PointInFRect(&point[2],&Block[count1][count2]->block)||SDL_PointInFRect(&point[3],&Block[count1][count2]->block)) {
            
            if( _file_array[count1][count2]=='*'){
                
                _ball->vy*=-1;
             if (_ball->vy>0) _ball->y+=_ball->radius*2;
             else _ball->y-=_ball->radius*2;
                _file_array[count1][count2]=' ';
            Break=true;
             break;
            } 
            
            else if( Block[count1][count2]->Block){


             _ball->vy*=-1; 
             if (_ball->vy>0) _ball->y+=_ball->radius*2;
             else _ball->y-=_ball->radius*2;
            Break=true;
             break;
              } 

            else {
                // printf("The point is not inside the rectangle.\n"); 
        }
            }
        count2++;
    }
    if (Break){
        break;
    }
    count1++;
}
    }
   }

void kill_SDL(SDL_Window *win){
            free(_ball);
            SDL_DestroyWindow(win);
            // printf("DESTORYED SUCESS");
            SDL_Quit();
            // printf("DESTORYED SUCESS 2");

}


void update_playable(void){
if (Block[0][0]!=NULL){
_playable.h=Block[0][0]->h*0.8;
_playable.w=Block[0][0]->w*6;
}
else{
_playable.h=(float)window_Height*0.03;
_playable.w=(float)window_Width *0.29;
}


if (cord_x<0) cord_x=1;
if (cord_x+_playable.w>window_Width) cord_x=window_Width-_playable.w;
_playable.x=cord_x;   // only this changes on movable..
_playable.y=window_Height*0.9;
// printf("CORD X AND CORD Y %f and %f    %d  %d \n",cord_x,cord_x,window_Height,window_Width);
}

SDL_Color get_pixel_color(SDL_Surface* surface, int x, int y){
        SDL_Color color = {0, 0, 0, 0};
    Uint32 *pixels = (Uint32 *)surface->pixels;
    Uint32 pixel = pixels[(y * surface->w) + x];

    SDL_PixelFormat *format = surface->format;
    SDL_GetRGB(pixel, format, &color.r, &color.g, &color.b);


  return color;  
}
void _eventcheck(SDL_Window *win){
    // printf("STARTED   1 \n");
    (void )win;
       ball_direction(_ball);
    //    printf("BALL DOWN");
       update_playable();
       SDL_SetRenderDrawColor(_render, 0,0,0,255) ;
       SDL_RenderClear(_render);
       SDL_SetRenderDrawColor(_render, 0,255,0,255) ;
       SDL_RenderFillRectF(_render,&_playable);
       SDL_SetRenderDrawColor(_render, 255,0,0,255) ;
       DrawCircle(_render, _ball);
    //    SDL_SetRenderDrawColor(_render, 92,52,20,255) ;
    //    printf("before desing DOWN");
       block_design(_render);
    //    printf("after desing DOWN");
       SDL_RenderPresent(_render);
}

void renderer(SDL_Window* win){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Event event;
    bool  run=true;
    static float friction=0.87;
    while(run){
       _lasttick=SDL_GetTicks(); _eventcheck(win);
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
            if( state[SDL_SCANCODE_P]){
                SDL_Delay(3000) ;               
                }                

            
            if(state[SDL_SCANCODE_LEFT]){
                velocity-=_playable.w/90;
                }
            if (state[SDL_SCANCODE_RIGHT]){
                velocity+=_playable.w/90;
            }
            if (state[SDL_SCANCODE_R]){
            kill_SDL(win);
            printf("KILLED");
            main();
            }
        velocity*=friction; // Change in velocity 
        // printf("VELOCITY %f , cord _X %f\n ",velocity,cord_x);
        float temp=cord_x;
        cord_x=cord_x+velocity;
        // printf("VELOCITY+cord_x %f , cord _X %f\n ",temp+velocity,cord_x);
        Sint32 computed=_lasttick+1000/FPS-SDL_GetTicks();
        if (computed>0){
        SDL_Delay(computed);
        }
    }
    kill_SDL(win);
    exit(0);
}

void free_all(void){

    // free(_ball); 
    Uint32 count1=0;
    while(count1<_size_file){
        Uint32 count2=0;
        while(count2<_size_lines){
        if(Block[count1][count2]!=NULL) {
            free(Block[count1][count2]);
                Block[count1][count2]=NULL;
        };
        if(_file_array[count1]!=NULL){
           free(_file_array[count1]) ;
           _file_array[count1]=NULL ;
        }
        count2++;
    } 
    //DrawBlocks(_render,_size_file,_size_lines)    ;

        count1++;
}
// printf("FREED \n");
}


int main(void){
    atexit(free_all);
    _ball =malloc(sizeof(Ball)) ;
    _ball->vx=1;
    _ball->vy=1;
    _ball->x=Bx;
    _ball->y=By;
    _ball->radius=Br; 
    SDL_Init(SDL_INIT_VIDEO);
    SDL_DisplayMode dm;
    if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
    SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
    return 1;
}
    printf("STARTED0 \n\n");
    state = SDL_GetKeyboardState(NULL);
    SDL_Window *_window=SDL_CreateWindow("GAME" ,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,dm.w*0.8,dm.h*0.8,SDL_WINDOW_RESIZABLE |SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
    _render=SDL_CreateRenderer(_window,0, SDL_RENDERER_ACCELERATED);
    initallize_level();
    renderer(_window);             
    return 0;
}




Uint32 get_window_Height(void){
    return window_Height;
}
Uint32 get_window_Width(void){
    return window_Width;
}



/* 
Direction Tree 

!  mathi batw tala -vy 

.
| talabatw mathi   -vy 
 



*/
