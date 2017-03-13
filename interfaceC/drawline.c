#include "drawline.h"

void putpixel (SDL_Surface *ecran, int x, int y, Uint32 pixel){
  int byteperpixel = theScreen->format->BytesPerPixel;
  Uint8 *p = (Uint8*)theScreen->pixels + y * theScreen->pitch + x * byteperpixel;
  *(Uint32 *)p = pixel;
}

void drawLine(SDL_Surface *Screen, int x0, int y0, int x1, int y1, Uint32 pixel) {
  int i;
  double x = x1 - x0; 
  double y = y1 - y0; 
  double length = sqrt( x*x + y*y ); 
  double addx = x / length; 
  double addy = y / length; 
  x = x0; 
  y = y0; 
  for ( i = 0; i < length; i += 1) { 
    putpixel(Screen, x, y, pixel ); 
    x += addx; 
    y += addy; 
		
  } 
}
