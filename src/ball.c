#include "../include/_ball.h"
// Ball _ball;
void DrawCircle(SDL_Renderer * _render,Ball *_ball)
{
        for (int y = -_ball->radius; y <= _ball->radius; y++) {
        for (int x = -_ball->radius; x <= _ball->radius; x++) {
            if (pow(x,2)+ pow(y,2) <= pow(_ball->radius,2)) {
                SDL_RenderDrawPoint(_render,_ball->x+ x, y+_ball->y);
                }
            }
        }

/*
Let's not use midpoint theorem , coz we don't only want the boarder of circle but whole circle drawn 
const int32_t diameter = (_ball.radius * 2);

   int32_t x = (_ball.radius - 1);
   int32_t y = 0;
   int32_t tx = 1;
   int32_t ty = 1;
   int32_t error = (tx - diameter);

   while (x >= y)
   {
      //  Each of the following renders an octant of the circle
      SDL_RenderDrawPoint(renderer, _ball.x + x, _ball.y - y);
      SDL_RenderDrawPoint(renderer, _ball.x + x, _ball.y + y);
      SDL_RenderDrawPoint(renderer, _ball.x - x, _ball.y - y);
      SDL_RenderDrawPoint(renderer, _ball.x - x, _ball.y + y);
      SDL_RenderDrawPoint(renderer, _ball.x + y, _ball.y - x);
      SDL_RenderDrawPoint(renderer, _ball.x + y, _ball.y + x);
      SDL_RenderDrawPoint(renderer, _ball.x - y, _ball.y - x);
      SDL_RenderDrawPoint(renderer, _ball.x - y, _ball.y + x);

      if (error <= 0)
      {
         ++y;
         error += ty;
         ty += 2;
      }

      if (error > 0)
      {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }

   */
}
