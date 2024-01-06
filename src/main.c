#include "../include/main.h"
#include "../include/_ball.h"
#include <SDL2/SDL_render.h>
Ball *_ball;
SDL_FRect _playable; // Add this line to declare the _playable variable
const Uint8 *state;
SDL_Renderer *_render ;

void ball_direction(Ball *_ball){
    _ball->radius=_playable.w/13;
    _ball->x+=_ball->vx;
//     printf("%f ball x  \n",_ball->x);
    _ball->y+=_ball->vy;
    if (_ball->x<=0 || _ball->x+_ball->radius*2 >=window_Width) _ball->vx*=-1 ;
    if (_ball->y<=0  ) _ball->vy*=-1; 

//     float _pre_x=_playable.w/3; //pre alert ball data ..
//     float _pre_y=_playable.h/3;

//    if (((_ball->x+_ball->radius)>=_playable.x-_pre_x && (_ball->x+_ball->radius)<=+_playable.x+_playable.w+_pre_x) && ((_ball->y+_ball->radius )>=_playable.y-_pre_y && (_ball->y+_ball->radius)<=_playable.y+_playable.h)){
    

    //    SDL_Surface *surface = SDL_GetWindowSurface(win);


    SDL_FPoint point = {_ball->x,_ball->y}; // Define your point
    if (SDL_PointInFRect(&point,&_playable)){
    printf("The point is inside the rectangle.\n");
        _ball->vy*=-1;
        _ball->y-=_ball->radius*3;
    } else {
        printf("The point is not inside the rectangle.\n");
    }


    // _ball->vy*=-1;
   }

void update_playable(void){
_playable.h=(float)window_Height*0.03;
_playable.w=(float)window_Width *0.11;
// _playable.h=(float)window_Height*0.53;
// _playable.w=(float)window_Width *0.61;
if (cord_x<0) cord_x=1;
if (cord_x+_playable.w>window_Width) cord_x=window_Width-_playable.w;
_playable.x=cord_x;   // only this changes on movable..
_playable.y=window_Height*0.9;
printf("CORD X AND CORD Y %f and %f    %d  %d \n",cord_x,cord_x,window_Height,window_Width);
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
    printf("STARTED   1 \n");
    (void )win;
       ball_direction(_ball);
    //    _ball->radius=0.05*window_Height*window_Width;
    //    printf("%f %f",_ball->x,_ball->y);
       update_playable();
       SDL_SetRenderDrawColor(_render, 0,0,0,255) ;
       SDL_RenderClear(_render);
       SDL_SetRenderDrawColor(_render, 0,255,0,255) ;
       SDL_RenderFillRectF(_render,&_playable);
       SDL_SetRenderDrawColor(_render, 255,0,0,255) ;
       DrawCircle(_render, _ball);
       SDL_RenderPresent(_render);
}

void renderer(SDL_Window* win){
    printf("STARTED___ \n");
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Event event;
    bool  run=true;
    static float friction=0.97;
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
                velocity-=_playable.w/150;
                }
            if (state[SDL_SCANCODE_RIGHT]){
                velocity+=_playable.w/150;
            }
            if (state[SDL_SCANCODE_R]){
            free(_ball);
            SDL_DestroyWindow(win);
            printf("DESTORYED SUCESS");
            SDL_Quit();
            printf("DESTORYED SUCESS 2");
            main();
            }
        velocity*=friction; // Change in velocity 
        printf("VELOCITY %f , cord _X %f\n ",velocity,cord_x);
        float temp=cord_x;
        cord_x=cord_x+velocity;
        printf("VELOCITY+cord_x %f , cord _X %f\n ",temp+velocity,cord_x);
        Sint32 computed=_lasttick+1000/FPS-SDL_GetTicks();
        if (computed>0){
        SDL_Delay(computed);
        }
    }
    free(_ball);

    SDL_DestroyWindow(win);
    printf("DESTORYED SUCESS");
    SDL_Quit();
    printf("DESTORYED SUCESS 2");
    exit(0);
}

int main(void){
    _ball =malloc(sizeof(Ball)) ;
    _ball->vx=5;
    _ball->vy=5;
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
    renderer(_window);             
    return 0;
}
