#include "equation.h"


int* developper(struct tree *t){
  int* tab = NULL;
  if(t->left){
    int* tabg = developper(t->left);
    int* tabd = developper(t->right);
    int g = tabg[0];
    int d = tabd[0];
    //gestion *
    if(*t->key == '*'){
      tab = malloc(sizeof(int)*(g+d-1));
      tab[0]= g+d-1;
      for(int i = 1; i<d-1;i++){
        tab[i] = 0;
      }
      for(int i = 1; i<g-1;i++){
        for(int j = 1; j<d-1;j++){
          tab[j+i-1] += tabg[i]*tabd[j];
        }
      }   
    }
    else{
      //gestion + et -
      if(g>d){
        tab = malloc(sizeof(int)*g);
        g = tab[0];
        for(int i = 1; i<g-1;i++){
          tab[i] = 0;
        }
        if (*t->key == '+'){
          for(int i = 1; i<d-1;i++){
            tab[i] = tabg[i]+tabd[i];
          }
          for(int i = d-1; i<g-1;i++){
            tab[i] = tabg[i];
          } 
        }
        else{
          for(int i = 1; i<d-1;i++){
            tab[i] = tabg[i]-tabd[i];
          }
          for(int i = d-1; i<g-1;i++){
            tab[i] = tabg[i];
          }
        }
      }
      else{
        tab = malloc(sizeof(int)*d);
        tab[0]=d;
        for(int i = 1; i<d-1;i++){
          tab[i] = 0;
        }
        if (*t->key == '+'){
          for(int i = 1; i<g-1;i++){
            tab[i] = tabg[i]+tabd[i];
          }
          for(int i = g-1; i<d-1;i++){
            tab[i] = tabd[i];
          }
        }
        else{
          for(int i = 1; i<g-1;i++){
            tab[i] = tabg[i]-tabd[i];
          }
          for(int i = g-1; i<d-1;i++){
            tab[i] = tabd[i];
          }
        }
      }
    }
    free(tabg);
    free(tabd);

  }
  else if (*t->key == 'x'){
    tab = malloc(sizeof(int)*3);
    tab[0]=3;
    tab[1]=0;
    tab[2]=1;
  }
  else{
    tab = malloc(sizeof(int)*1);
    tab[0] = 2;
    tab[1] = *t->key;
  }
  return tab;
}

int main() {
  char *s = "42+23*4*X";
  int* tab = developper(parse(s));
  for(int i = 1; i<tab[0];i++){
    printf("%d",tab[i]);
  }
  free(tab);
}

