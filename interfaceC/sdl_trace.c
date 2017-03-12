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

int posiy(char*str){
  return solve(parse(str))*10;
}



void paused()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
} 

void trace(char* str)
{
    SDL_Surface *ecran = NULL;
    SDL_Renderer* renderer = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) == -1) // Démarrage de la SDL. Si erreur :
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Écriture de l'erreur
        exit(EXIT_FAILURE); // On quitte le programme
    }
    //ecran = SDL_SetVideoMode(1000, 1000, 32, SDL_SWSURFACE);
    SDL_CreateWindowAndRenderer(1000, 1000, 32, &ecran, &renderer);
    if (ecran == NULL) // Si l'ouverture a échoué, on le note et on arrête

    {

        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());

        exit(EXIT_FAILURE);

    }

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    int a = posiy(swap(str,'x',-50));
    int b = 0;
    for(int i = 10;i<1000;i += 10){
      b= posiy(swap(str,'x',i-50./10));
      SDL_RenderDrawLine(renderer,i-10,b,i,a);
      a= b;
    }

    SDL_Flip(ecran);
     
    paused();

    SDL_Quit(); // Arrêt de la SDL (libération de la mémoire)

}
