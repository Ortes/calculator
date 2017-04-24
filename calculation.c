# include "calculation.h"
# include <math.h>

double calculation(double a, double b, char operation)
{
  switch (operation){
    case '+' : return a + b;
      break;
	
    case '-' : return a - b;
      break;
	
    case '*' : return a * b;
      break;
    
    case '/' :
      //if (b == 0)
        //errx(1, "divide by 0");
      return a / b;
      break;
	
    case '^' : return pow(a, b);
      break;

	default : errx(1, "internal error unknown operator");
      break;
  }
  return 0;
}

double solve(struct tree *t) {
  if (t->left)
    return calculation(solve(t->left), solve(t->right), t->key[0]);
  return *(double *)(t->key);
}

double solveX(struct tree *t, double x) {
  if (t->left)
    return calculation(solveX(t->left, x), solveX(t->right, x), t->key[0]);
  if (t->key[6] == -1 && t->key[7] == -1 && t->key[0] == 'x')
    return x;
  return *(double *)(t->key);
}

double solveXN(struct tree *t, double x, size_t n) {
  if (t->left)
    return calculation(solveXN(t->left, x, n), solveXN(t->right, x, n), t->key[0]);
  if (t->key[6] == -1 && t->key[7] == -1 && t->key[0] == 'x')
    return x;
  if (t->key[6] == -1 && t->key[7] == -1 && t->key[0] == 'n')
    return (double)n;
  return *(double *)(t->key);
}
