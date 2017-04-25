# include <stdio.h>
# include "parsing.h"
# include "build_exp.h"
# include "calculation.h"
# include "equation.h"

int main(int argc, char *argv[]) {
  //char *s = "42.1+23*4/(1+5)";
  char *e = "42+x*(1+x)";
  //char *a = "1-2";
  //printf("%s\n", s);
  if (argc > 1){
    //printf("%lf\n", solve(parse(argv[1])));
    printf("%s\n",argv[1]);
  }
  else{
    //printf("%lf\n", solve(parse(s)));
    printf("%s\n",e);
    double *tab = developper(parse(e));
    for(int i =1;i<tab[0];i++){
      printf("%lf ",tab[i]);
    }
    free(tab);
  }
}
