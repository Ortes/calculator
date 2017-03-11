# include <stdio.h>
# include "parsing.h"
# include "build_exp.h"

int main() {
  char *s = "2+3";
  printf(solve(build(s)));
}
