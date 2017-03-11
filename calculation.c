# include "calculation.h"

double calculation(double a, double b, double operation)
{
  char opp = *((char *)operation);
  switch(operation){
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
	
    default : errx(1, "internal error unknown operator");
      break;
  }
  return 0;
}

double solve(struct tree *t, double x) {
  if (t->left)
    return calculation(solve(t->left, x), solve(t->right, x), t->key);
  return t->key;
}
