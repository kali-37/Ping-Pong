#include"../include/blocks.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <stdint.h>

block_size* Block[255][255];

Uint32 _size_file=UINT32_MAX;
Uint32 _size_lines=UINT32_MAX;



void block_design(SDL_Renderer* _render){
    Uint32 window_Height=get_window_Height();
    Uint32 window_Width=get_window_Width();
    FILE *file;
    char *_file_array[255];
    file = fopen("../Levels/level1.txt","r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return;
    }
    int count=0;
    char buffer[255];
    while(fgets(buffer,255,file)){
        _file_array[count]=malloc(sizeof(buffer));
        strcpy(_file_array[count], buffer);
        count++;
    }
    printf("FILE >>> %lu , count >> %d ",strlen(_file_array[1] )-1  ,count) ;
    _size_file=count; // 7 
    _size_lines=strlen(_file_array[1])-1;  // Deduce \n  , aroudnd 36
    int height_of_block=(window_Height/3)/count; // We will make our stuffs within window_Height/3 
    printf(" window height : %d \n count : %d THUS height_of_blockk is %d\n",window_Height,count,height_of_block);
    // SDL_Delay(5000);
    int width_of_block=window_Width/_size_lines;
    Uint32 count1=0;
    while(count1<_size_file){
        Uint32 count2=0;
        while(count2<_size_lines){
        Block[count1][count2] = malloc(sizeof(*Block[count1][count2]));
       if (Block[count1][count2] == NULL) {
           printf("Memory allocation failed\n");
           exit(1);
       }
        Block[count1][count2]->x=Block[count1][count2]->block.x=count2*width_of_block;
        Block[count1][count2]->y=Block[count1][count2]->block.y=count1*height_of_block;
        Block[count1][count2]->h=Block[count1][count2]->block.h=height_of_block;
        Block[count1][count2]->w=Block[count1][count2]->block.w=width_of_block;         
        if (_file_array[count1][count2]=='=')  Block[count1][count2]->Block=true;
        else Block[count1][count2]->Block=false;
        
        if (_file_array[count1][count2]=='=') SDL_RenderFillRectF(_render,&Block[count1][count2]->block);
        
        count2++;
       }
       count1++;
    } 
    //DrawBlocks(_render,_size_file,_size_lines)    ;

} 

// void DrawBlocks(SDL_Renderer* _render,int _size_file,int _size_lines){
//     while()
//     block->h=
// 
// 
//     }     
//     
// 
//    return ; 
// }
