#ifndef BUILD_EXP_H_
#define BUILD_EXP_H_

#include <stdlib.h>
#include <math.h>
#include "ast.h"
#include "char_macros.h"

#define OP_PRIORITY(_CHAR) ((_CHAR == '+' || _CHAR == '-') ? 1 : (_CHAR == '*' || _CHAR == '/') ? 2 : 3)

struct tree* build_exp(char *s);

#endif
