#include "equation.h"


double* developper(struct tree *t){
  double* tab = NULL;
  if(t->left){
    double* tabg = developper(t->left);
    double* tabd = developper(t->right);
    double g = tabg[0];
    double d = tabd[0];
    //gestion *
    if(get_char(t) == '*'){
      tab = malloc(sizeof(double)*(g+d-2));
      tab[0]= g+d-2;
      for(int i = 1; i<tab[0];i++){
        tab[i] = 0;
      }
      for(int i = 1; i<g;i++){
        for(int j = 1; j<d;j++){
          tab[j+i-1] += tabg[i]*tabd[j];
        }
      }   
    }
    else{
      //gestion + et -
      if(g>d){
        tab = malloc(sizeof(double)*g);
        tab[0] = g;
        for(int i = 1; i<g;i++){
          tab[i] = 0;
        }
        if (get_char(t) == '+'){
          for(int i = 1; i<d;i++){
            tab[i] = tabg[i]+tabd[i];
          }
          for(int i = d; i<g;i++){
            tab[i] = tabg[i];
          } 
        }
        else{
          for(int i = 1; i<d;i++){
            tab[i] = tabg[i]-tabd[i];
          }
          for(int i = d; i<g;i++){
            tab[i] = tabg[i];
          }
        }
      }
      else{
        tab = malloc(sizeof(double)*d);
        tab[0]=d;
        for(int i = 1; i<d-1;i++){
          tab[i] = 0;
        }
        if (get_char(t) == '+'){
          for(int i = 1; i<=g;i++){
            tab[i] = tabg[i]+tabd[i];
          }
          for(int i = g; i<d;i++){
            tab[i] = tabd[i];
          }
        }
        else{
          for(int i = 1; i<=g;i++){
            tab[i] = tabg[i]-tabd[i];
          }
          for(int i = g; i<d;i++){
            tab[i] = -tabd[i];
          }
        }
      }
    }
    free(tabg);
    free(tabd);

  }
  else if (get_char(t) == 'x'){
    tab = malloc(sizeof(double)*3);
    tab[0]=3;
    tab[1]=0;
    tab[2]=1;
  }
  else{
    tab = malloc(sizeof(double)*2);
    tab[0] = 2;
    tab[1] = get_number(t);
  }
  return tab;
}

