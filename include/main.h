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
#include"blocks.h"

static Uint32 window_Height =500;
static Uint32 window_Width= 500;
static double velocity=0;
static float cord_x=0;
void renderer(SDL_Window *win);
static Sint32 _lasttick;
#define FPS 200

static double Bx=300;
static double By=300;
static double Br=1.5;
int main(void);

Uint32 get_window_Height(void);
Uint32 get_window_Width(void);
