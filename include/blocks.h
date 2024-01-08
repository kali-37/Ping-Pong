#include<SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_stdinc.h>
#include<stdio.h>

#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>

void block_design(SDL_Renderer*);
void DrawBlocks(SDL_Renderer*,int,int);
void initallize_level(void);
extern Uint32 get_window_Height(void); // As they are static we had to do this to get values 
extern Uint32 get_window_Width(void);
extern Uint32 _size_file;
extern Uint32 _size_lines; 
typedef struct{
    long x;
    long y;
    long h;
    long w;
    bool Block;
    bool eatable;
    SDL_FRect block;
}block_size ;


extern block_size *Block[255][255];

extern char* _file_array[255];
