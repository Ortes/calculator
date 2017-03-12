#include "build_exp.h"

struct tree* __build_exp(char **s)
{
  struct tree* op_node;
  if (**s == '(')
    op_node = build_exp(++(*s));
  else {
    op_node = create_node(atof(*s));
    while (IS_NUMBER(**s) || **s == '.') (*s)++;
  }

  while (**s) {
    struct tree *node = malloc(sizeof (struct tree));
    node->left = op_node;
    op_node = node;
    store_char(op_node, **s);
    (*s)++;
    if (**s == '(')
      op_node->right = build_exp(++(*s));
    else {
      op_node->right = create_node(atof(*s));
      while (IS_NUMBER(**s) || **s == '.') (*s)++;
    }
    if (**s == ')')
      return op_node;
  }
  return op_node;
}

struct tree* build_exp(char *s) {
  char *tmps = s;
  return __build_exp(&tmps);
}
