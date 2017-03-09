#include <stdlib.h>

struct tree {
  char key[8];
  struct tree *left, *right;
};

struct tree* append_top(struct tree *tree, char opp);
void append_leaf(struct tree *tree, char num);
