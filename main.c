# include <stdio.h>
# include "parsing.h"

int main() {
  char *s = " 1+ #\t 4";
  printf("%d\n", parse(s));
  printf(s);
}
