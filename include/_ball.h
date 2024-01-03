
#include <stdint.h>
#include <SDL2/SDL.h>

typedef struct {
    int32_t ball_x;
    int32_t ball_y;
} Ball;

extern Ball _ball; // Fix: Add complete declaration of the variable 'ball'

void DrawCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius);
