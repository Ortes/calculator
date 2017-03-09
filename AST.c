#include"AST.h"

static inline struct tree* create_node(double x)
{
  struct tree *node = malloc(sizeof(struct tree));
  node->left = NULL;
  node->right = NULL;
  *(float *)node->key = x;
}

struct tree* append_top(struct tree* tree, double x)
{
  struct tree *node = create_node(x);
  node->left = tree;
  return node;
}

void append_leaf(struct tree* tree, double x)
{
  struct tree *node = create_node(x);
  if(!tree->left)
  {
    tree->left = node;
  }
  else
  {
    tree->right = node;
  }
}
