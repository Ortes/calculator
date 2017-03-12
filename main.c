# include <stdio.h>
# include "parsing.h"
# include "build_exp.h"
# include "calculation.h"

int main() {
  char *s = "2+3";
  printf("%lf\n", solve(build_exp(s)));
}
