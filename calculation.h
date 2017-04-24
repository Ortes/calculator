#ifndef CALCULATION_H_
#define CALCULATION_H_

# include <err.h>
# include "ast.h"

double solve(struct tree *t);
double solveX(struct tree *t, double x);
double solveXN(struct tree *t, double x, size_t n);

#endif
