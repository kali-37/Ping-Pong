#include"../include/blocks.h"

block_size* Block[255][255]={0};

Uint32 _size_file=UINT32_MAX;
Uint32 _size_lines=UINT32_MAX;

char* _file_array[255];

void initallize_level(void){
    FILE *file;
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
    // printf("FILE >>> %lu , count >> %d ",strlen(_file_array[1] )-1  ,count) ;
    _size_file=count; // 7 
    _size_lines=strlen(_file_array[1])-1;  // Deduce \n  , aroudnd 36 
}

void block_design(SDL_Renderer* _render){
    Uint32 window_Height=get_window_Height();
    Uint32 window_Width=get_window_Width();
    float height_of_block=((float)window_Height/3)/_size_file; // We will make our stuffs within window_Height/3 
    float width_of_block=(float)window_Width/_size_lines;
    Uint32 count1=0;
   while(count1<_size_file){
        Uint32 count2=0;
        while(count2<_size_lines){
        Block[count1][count2] = malloc(sizeof(*Block[count1][count2]));
       if (Block[count1][count2] == NULL) {
        //    printf("Memory allocation failed\n");
           exit(1);
       }
        if (_file_array[count1][count2]!='*'){
        Block[count1][count2]->x=Block[count1][count2]->block.x=count2*width_of_block;
        Block[count1][count2]->y=Block[count1][count2]->block.y=count1*height_of_block;
        Block[count1][count2]->h=Block[count1][count2]->block.h=height_of_block;
        Block[count1][count2]->w=Block[count1][count2]->block.w=width_of_block;         

        if (_file_array[count1][count2]=='=')  {
            Block[count1][count2]->Block=true;
       SDL_SetRenderDrawColor(_render, 92,52,20,255) ;
        // printf("\nSO FILE ARRAY");
        SDL_RenderFillRectF(_render,&Block[count1][count2]->block);
        } 
        else{
             Block[count1][count2]->Block=false;
        }
        } 
        else{
        Block[count1][count2]->x=Block[count1][count2]->block.x=count2*width_of_block+width_of_block/3;
        Block[count1][count2]->y=Block[count1][count2]->block.y=count1*height_of_block+height_of_block/3;
        Block[count1][count2]->h=Block[count1][count2]->block.h=height_of_block/3;
        Block[count1][count2]->w=Block[count1][count2]->block.w=width_of_block/3;         

               SDL_SetRenderDrawColor(_render, 66,170,254,255) ;
        SDL_RenderFillRectF(_render,&Block[count1][count2]->block);


        }


        count2++;
       }
       count1++;
    } 

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
