
#include <SDL2/SDL_stdinc.h>
#include<stdio.h>

#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>


extern Uint32 get_window_Height(void); // As they are static we had to do this to get values 
extern Uint32 get_window_Width(void);


typedef struct{
    long x;
    long y;
    long h;
    long w;
    bool Block;
}block_size ;


extern block_size* Block[255][255];









