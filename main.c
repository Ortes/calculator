# include <stdio.h>
# include "parsing.h"

int main() {
  char *s = " 1 + \t4 +sqrt (3 * (1 + 3) / sin(7 ^6) + n #";
  printf("%d\n", parse(s));
  printf(s);
}
