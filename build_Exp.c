#include "AST.c"
#include <stdlib.h>
#include <math.h>

struct tree* build_Exp(char *s)
{
  struct tree* ast = (struct tree*) malloc(sizeof (struct tree));
  ast->key = '0';
  ast->left = NULL;
  ast->right = NULL;
  ast = append_top(ast, '+');

  while(s)
  {
    if (*s == '(')
    {
      struct tree* node = build_Exp(*(s+1));
      while(*s != ')'){s += 1;}
      ast = append_leaf_ast(ast, struct tree* nwast);
    }

    else if (*s == '+' || *s == '*' || *s == '-' || *s == '/')
    {
      ast = append_top(ast, *s);
    }

    else if (*s == ')')
    {
      return ast;
    }

    else if ((*s >= '0') && (*s <= '9'))
    {
      char *num = "";
      while ((*(s+1) >= '0') && (*(s+1) <= '9'))
      {
        num += *s;
        s += 1;
      }
      num += *s;
      append_leaf(ast, num);
    }
    s += 1;
  }
}
