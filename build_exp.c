#include "build_exp.h"
#include "parsing.h"

struct tree* __build_exp(char **s)
{
  struct tree* op_node;
  if (**s == '(') {
    (*s)++;
    op_node = __build_exp(s);
  } 
  else 
  {
    if (IS_LETTER(**s)) {
      if (**s == 'n' || **s == 'x') {
        op_node = create_node(0);
        store_char(op_node, **s);
        (*s)++;
      }
      else {
        int nb = sizeof(funcs)/sizeof(funcs[0]);
        char *s2 = *s;
        int boolArray[(sizeof(funcs)/sizeof(funcs[0]))];
        for (int i = 0; i < (sizeof(funcs) / sizeof(funcs[0])); i++) boolArray[i] = 42;
        int seek = 0;
        while (nb) {
          for (int i = 0; i < (sizeof(funcs) / sizeof(funcs[0])); i++) {
            if (boolArray[i]) {
              if (funcs[i][seek] != **s) {
                if (funcs[i][seek] == '\0') {
                  char ch;
                  switch (i) {
                    case 0: ch = 's';
                            break;
                    case 1: ch = 'e';
                            break;
                    case 2: ch = 'l';
                            break;
                    case 3: ch = '@';
                            break;
                    case 4: ch = '#';
                            break;
                    case 5: ch = 'j';
                            break;
                  }
                  (*s)++;
                  op_node = __build_exp(s);
                  struct tree *node = malloc(sizeof(struct tree));
                  node->left = op_node;
                  op_node = node;
                  node = create_node(0);
                  op_node->right = node;
                  store_char(op_node, ch);
                  (*s)--;
                  boolArray[0] == 1337;
                  nb = 0;
                }
                else {
                  boolArray[i] = 0;
                  nb--;
                }
              }
            }
          }
          (*s)++;
          seek++;
        }
      }
    } 
    else 
    {
      op_node = create_node(atof(*s));
      while (IS_NUMBER(**s) || **s == '.' || **s  == 'e' || **s == 'E') (*s)++;
    }
  }
  int is_rot_possible = 0;

  if (**s == ')') {
    (*s)++;
    return op_node;
  }
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
      if (IS_LETTER(**s)) {
        if (**s == 'n' || **s == 'x') {
          op_node->right = create_node(0);
          store_char(op_node->right, **s);
          (*s)++;
        }
        else{
          int nb = sizeof(funcs)/sizeof(funcs[0]);
          char *s2 = *s;
          int boolArray[(sizeof(funcs)/sizeof(funcs[0]))];
          for (int i = 0; i < (sizeof(funcs) / sizeof(funcs[0])); i++) boolArray[i] = 42;
          int seek = 0;
          while (nb) {
            for (int i = 0; i < (sizeof(funcs) / sizeof(funcs[0])); i++) {
              if (boolArray[i]) {
                if (funcs[i][seek] != **s) {
                  if (funcs[i][seek] == '\0') {
                    char ch;
                    switch (i) {
                      case 0: ch = 's';
                              break;
                      case 1: ch = 'e';
                              break;
                      case 2: ch = 'l';
                              break;
                      case 3: ch = '@';
                              break;
                      case 4: ch = '#';
                              break;
                      case 5: ch = 'j';
                              break;
                    }
                    (*s)++;
                    struct tree *node = malloc(sizeof(struct tree));
                    node = __build_exp(s);
                    struct tree *tmp = malloc(sizeof(struct tree));
                    tmp->left = node;
                    tmp->right = create_node(0);
                    op_node->right = tmp;
                    store_char(tmp, ch);
                    (*s)--;
                    boolArray[0] == 1337;
                    nb = 0;
                  }
                  else {
                    boolArray[i] = 0;
                    nb--;
                  }
                }
              }
            }
            (*s)++;
            seek++;
          }
        }
      } 
      else {
        op_node->right = create_node(atof(*s));
        while (IS_NUMBER(**s) || **s == '.' || **s  == 'e' || **s == 'E') (*s)++;
      }
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
