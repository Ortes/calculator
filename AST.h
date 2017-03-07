#include <stdlib.h>

struct tree {
  char key;
  struct tree *left, *right;
};

struct tree* append_top(struct tree *tree, char opp);
struct tree* append_leaf(struct tree *tree, char num);
