#include "build_exp.h"

struct tree* build_exp(char **s)
{
  struct tree* op_node = malloc(sizeof (struct tree));
  if (**s == '(')
    op_node->left = build_exp(++(*s));
  else {
    op_node->left = create_node(atof(*s));
    while (IS_NUMBER(**s) || **s == '.') (*s)++;
  }
  
  for (; **s; (*s)++)
  {
    store_char(**s);
    (*s)++;
    if (**s == '(')
      op_node->right = build_exp(++s);
    else {
      op_node->right = create_node(atof(*s));
      while (IS_NUMBER(**s)) (*s)++;
    }
    if (**s == ')')
      return op_node;
    struct tree *node = malloc(sizeof (struct tree));
    node->left = op_node;
    op_node = node;
  }
}
