#ifndef DRAWLINE_H_
#define DRAWLINE_H_



#include <SDL.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void putpixel (SDL_Surface *ecran, int x, int y, Uint32 pixel);
void drawLine(SDL_Surface *Screen, int x0, int y0, int x1, int y1, Uint32 pixel);

#endif
