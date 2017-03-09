#include"AST.h"

struct tree* append_top(struct tree* tree, char* opp)
{
  struct tree *node = (struct tree*) malloc(sizeof (struct tree));
  node->key = opp;
  node->left = tree;
  node->right = NULL;
  return node;
}

struct tree* append_leaf(struct tree* tree, char* num)
{
  struct tree *node = (struct tree*) malloc(sizeof (struct tree));
  node->key = num;
  node->left = NULL;
  node->right = NULL;
  if(!tree->left)
  {
    tree->left = node;
  }
  else
  {
    tree->right = node;
  }
  return tree;
}
