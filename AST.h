#ifndef AST_H_
#define AST_H_

#include <stdlib.h>

struct tree {
  char *key;
  struct tree *left, *right;
};

static inline void store_number(struct tree *t, double x) {
  *(float *)node->key = x;
}

static inline void store_char(struct tree *t, char c) {
  tree->key[7] = 0xFF;
  tree->key[6] = 0xFF;
  tree->key[0] = c;
}

static inline struct tree* create_node(double x)
{
  struct tree *node = malloc(sizeof(struct tree));
  node->left = NULL;
  node->right = NULL;
  store_number(node, x);
}

#endif
