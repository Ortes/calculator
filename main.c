# include <stdio.h>
# include "parsing.h"
# include "build_exp.h"
# include "calculation.h"

int main(int argc, char *argv[]) {
  char *s = "2+3";
  if (argc > 1)
    printf("%lf\n", solve(parse(argv[1])));
  else
    printf("%lf\n", solve(parse(s)));
}
