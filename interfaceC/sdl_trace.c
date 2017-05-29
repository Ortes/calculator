#include "sdl_trace.h"

char* swap(char* str,char x,char a){
  char *str2 = malloc(sizeof(char)*strlen(str));
  strcpy(str2,str);
  for(int i;str2[i] != '\0';i++){
    if(str2[i] == x){
      str2[i] == a;
    }
  }
  return str2;
}

void paused()
{
  int continuer = 1;
  SDL_Event event;
  
  while (continuer) {
    SDL_WaitEvent(&event);
    switch(event.type) {
    case SDL_QUIT:
      continuer = 0;
    }
  }
}

void draw_axis(SDL_Surface *screen) {
  //drawLine(screen, 499, 0, 499, 1000, 0);
  drawLine(screen, 500, 0, 500, 1000, 0);
  //drawLine(screen, 0, 501, 1000, 501, 0);
  drawLine(screen, 0, 500, 1000, 500, 0);
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 500; j++) {
      putpixel(screen, j * 2, i * 50, 0);
      putpixel(screen, i * 50, j * 2, 0);
    }
    /*putpixel(screen, i * 50, 499, 0);
    putpixel(screen, i * 50, 498, 0);
    putpixel(screen, 501, i * 50, 0);
    putpixel(screen, 502, i * 50, 0);*/ 
  }
}

void trace(char* str)
{
  SDL_Surface *ecran = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) == -1) // Démarrage de la SDL. Si erreur :
    {
      fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Écriture de l'erreur
      exit(EXIT_FAILURE); // On quitte le programme
    }
  //ecran = SDL_SetVideoMode(1000, 1000, 32, SDL_SWSURFACE);
  ecran = SDL_SetVideoMode(1000, 1000, 32, SDL_HWSURFACE);
  if (ecran == NULL) // Si l'ouverture a échoué, on le note et on arrête

    {
      fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());

      exit(EXIT_FAILURE);

    }

  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

  draw_axis(ecran);
  int y;

	char *s2 = str;
	while (*s2 && *s2 == 'n') s2++;
	if (!*s2) {
		int lastY = 1000 - (solveX(parse(str), (-1 - 500) / (1000. / 2 / 10)) * (1000 / 2 / 10) + 500);
		for(int i = 0; i < 1001; i++) {
			y = 1000 - (solveX(parse(str), (i - 500) / (1000. / 2 / 10)) * (1000 / 2 / 10) + 500);
			if(y < 1000 && y >= 0) {
				drawLine(ecran, i - 1, lastY, i, y, 0);
			}
			lastY = y;
		}
	} else {
		for (size_t n = 0; n < 20; n++) {
			int lastY = 1000 - (solveXN(parse(str), (-1 - 500) / (1000. / 2 / 10), n) * (1000 / 2 / 10) + 500);
			for(int i = 0; i < 1001; i++) {
				y = 1000 - (solveXN(parse(str), (i - 500) / (1000. / 2 / 10), n) * (1000 / 2 / 10) + 500);
				if(y < 1000 && y >= 0) {
					drawLine(ecran, i - 1, lastY, i, y, 0);
				}
				lastY = y;
			}
		}
	}

  SDL_Flip(ecran);
     
  paused();

  SDL_Quit(); // Arrêt de la SDL (libération de la mémoire)

}
