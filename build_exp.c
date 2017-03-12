#include "build_exp.h"

struct tree* __build_exp(char **s)
{
  struct tree* op_node;
  if (**s == '(') {
    (*s)++;
    op_node = __build_exp(s);
  } else {
    op_node = create_node(atof(*s));
    while (IS_NUMBER(**s) || **s == '.') (*s)++;
  }
  int is_rot_possible = 0;

  while (**s) {
    struct tree *node = malloc(sizeof (struct tree));
    node->left = op_node;
    op_node = node;
    store_char(op_node, **s);
    (*s)++;
    if (**s == '(') {
      (*s)++;
      op_node->right = __build_exp(s);
    } else {
      op_node->right = create_node(atof(*s));
      while (IS_NUMBER(**s) || **s == '.') (*s)++;
    }
    if (is_rot_possible) {
      if (OP_PRIORITY(get_char(op_node)) > OP_PRIORITY(get_char(op_node->left))) {
	struct tree *tmp = op_node;
	op_node = op_node->left;
	tmp->left = op_node->right;
	op_node->right = tmp;
      }
    }
    if (**s == ')') {
      (*s)++;
      return op_node;
    }
    is_rot_possible = 1;
  }
  return op_node;
}

struct tree* build_exp(char *s) {
  char *tmps = s;
  return __build_exp(&tmps);
}
