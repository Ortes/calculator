#ifndef PARSING_H_
#define PARSING_H_

# include <stdlib.h>
# include <stdio.h>
# include <err.h>
# include "build_exp.h"

# define S_EXP_START 0
# define S_NUMBER 1
# define S_DECIMAL_NUMBER 2
# define S_OPERATOR 3
# define S_LETTER 4
# define S_FUNC 5

# define T_CALC 0
# define T_FUNCTION 1

struct tree *parse(char *s);

#endif
