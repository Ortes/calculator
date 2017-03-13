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

int posiy(char*str,double i){
  int x =1000-solveX(parse(str),i)-500;
  if(x <1000 && x>1)
    return x;
  else
    return 3000;
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
    //int a = posiy(str,-50);
    int b = 0;
    for(int i = 0;i<1000;i += 1){
        b= posiy(str,i-50./10);
        //drawLine(ecran,i-10,b,i,a,0);
        //a= b;
        if(b !=3000)
          putpixel(ecran,i,b,0);
      
    }

    SDL_Flip(ecran);
     
    paused();

    SDL_Quit(); // Arrêt de la SDL (libération de la mémoire)

}
