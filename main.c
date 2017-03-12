# include <stdio.h>
# include "parsing.h"
# include "build_exp.h"
# include "calculation.h"

int main(int argc, char *argv[]) {
  double x = 4;
  char *s = "2*n+3*x";
  printf("%s\n", s);
  if (argc > 1)
    for (size_t i = 0; i < 30; i++)
      printf("%lf\n", solveXN(parse(argv[1]), x, i));
  else
    for (size_t i = 0; i < 30; i++)
      printf("%lf\n", solveXN(parse(s), x, i));
}
