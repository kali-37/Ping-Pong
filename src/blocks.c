#include"../include/blocks.h"

block_size* Block[255][255];


void block_design(void){
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
    int _size_file=count; // 7 
    int _size_lines=strlen(_file_array[1])-1;  // Deduce \n  , aroudnd 36

    int height_of_block=(window_Height/3)/count; // We will make our stuffs within window_Height/3 
    int width_of_block=window_Width/_size_lines;



int count1=0;
while(count1<_size_file){
    int count2=0;
    while(count2<_size_lines){
    // Allocate memory for the struct before accessing its members
    Block[count1][count2] = malloc(sizeof(*Block[count1][count2]));
    if (Block[count1][count2] == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    Block[count1][count2]->x=count2*width_of_block;
    Block[count1][count2]->y=count1*width_of_block;
    Block[count1][count2]->h=height_of_block;
    Block[count1][count2]->w=width_of_block;         
    if (_file_array[count1][count2]=='=')  Block[count1][count2]->Block=true;
    else Block[count1][count2]->Block=false;
    count2++;
   }
   count1++;
} 
    printf(" WE HAVE %d ", Block[2][35]->Block);
}
