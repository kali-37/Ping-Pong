#include <limits.h>
#include <unistd.h>
#include <stdint.h>
#include<time.h>
#include<stdio.h>
#include "../SDL/include/SDL2/SDL.h"
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>

#include<SDL2/SDL.h>
//#include<SDL2/SDL_image.h>
//#include<SDL2/SDL_ttf.h>
// static Uint32 momentum=0 ;
static Uint32 window_Height =0;
static Uint32 window_Width= 0;
static double velocity=0;
static Sint32 cord_x=0;
// static Sint32 velocity=0;
// static Uint32 friction=i-10;
// static Uint32 cord_y;
void renderer(SDL_Window *win);
static Sint32 _lasttick;
#define FPS 200

static double Bx=100;
static double By=100;
static double Br=5;
// static double Theta=60;

int main(void);
