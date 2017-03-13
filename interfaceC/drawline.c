#include "drawline.h"

void putpixel (SDL_Surface *ecran, int x, int y, Uint32 pixel){
  int byteperpixel = ecran->format->BytesPerPixel;
  Uint8 *p = (Uint8*)ecran->pixels + y * ecran->pitch + x * byteperpixel;
  *(Uint32 *)p = pixel;
}

void drawLine(SDL_Surface *Screen, int x0, int y0, int x1, int y1, Uint32 pixel) {
  double x = x1 - x0;
  double y = y1 - y0;
  double length = sqrt(x*x + y*y);
  double addx = x / length;
  double addy = y / length;
  x = x0;
  y = y0;
  for (int i = 0; i < length; i++) {
    if (y < 1000 && y >= 0 && x < 1000 && x >= 0)
      putpixel(Screen, x, y, pixel);
    x += addx;
    y += addy;
  } 
}
