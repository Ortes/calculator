#ifndef CALCULATION_H_
#define CALCULATION_H_

# include <err.h>
# include "ast.h"

# define GET_VALUE(_TREE) *(double *)(_TREE->key)
# define SET_VALUE(_TREE, _VALUE) *(double *)(_TREE->key) = _VALUE

double solve(struct tree *t);
double solveX(struct tree *t, double x);
double solveXN(struct tree *t, double x, size_t n);

#endif
