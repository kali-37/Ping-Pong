#include<stdio.h>
#include<stdbool.h>
#include <limits.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include<time.h>
#include<SDL2/SDL_mixer.h>
#include "../SDL/include/SDL2/SDL.h"
#include "../SDL/include/SDL2/SDL_rect.h"
#include "../SDL/include/SDL2/SDL_stdinc.h"
#include "../SDL/include/SDL2/SDL_render.h"
#include "../SDL/include/SDL2/SDL_events.h"
#include"blocks.h"
#include "../include/_ball.h"

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
void _play_sound(char);
