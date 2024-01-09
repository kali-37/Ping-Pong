#include <stdint.h>
#include <SDL2/SDL.h>
#include <math.h>
typedef struct{
    double  x;
    double  y;
    double  radius;
    double  theta;
    double vx;
    double vy;
}Ball;
extern Ball *_ball; 
void DrawCircle(SDL_Renderer * renderer,Ball *_ball);
