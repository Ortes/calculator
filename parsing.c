# include "parsing.h"

#define FUNCTION_NUMBER sizeof (funcs) / sizeof (*funcs)

int chknrmspace(char *s) {
  static char *funcs[] = {"sqrt",
			  "exp",
			  "ln",
			  "cos",
			  "sin",
			  "tan"};
  int is_func[FUNCTION_NUMBER];
  for (size_t i = 0; i < FUNCTION_NUMBER; i++) is_func[i] = 1;
  int nb_func_left = FUNCTION_NUMBER;
  int pos_in_func_def = 0;
  printf("%u\n", FUNCTION_NUMBER);
  
  int state = S_EXP_START;
  int type = T_CALC;
  int parentesis = 0;
  
  for (; *s; ++s) {
    if (IS_NUMBER(*s)) {
      if (state != S_OPERATOR && state != S_EXP_START)
	return -1;
      state = S_NUMBER;
    }

    else if (*s == '.') {
      if (state == S_NUMBER)
	state = S_DECIMAL_NUMBER;
      else
	return -1;
    }
    
    else if (IS_LETTER(*s)) {
      if (state != S_OPERATOR && state != S_EXP_START)
	return -1;
      state = S_LETTER;
      for (size_t i = 0; i < FUNCTION_NUMBER; i++) {
	if (is_func[i] && funcs[i][pos_in_func_def] != *s) {
	  if (funcs[i][pos_in_func_def]) {
	    is_func[i] = 0;
	    nb_func_left--;
	  }
	  else
	    state = S_FUNC;
	}
      }
      if (nb_func_left <= 0 && pos_in_func_def > 0)
	return -1;
      pos_in_func_def++;
    }

    else if (*s == '(') {
      if (state != S_OPERATOR)
	return -1;
      parentesis++;
      state = S_EXP_START;
    }
    
    else if (*s == ')') {
      if (state != S_NUMBER)
	return -1;
      parentesis--;
      if (parentesis < 0)
	return -1;
    }

    else if (IS_SPACES(*s))
      continue;
    
    else
      return -1;
  }
  return type;
}

int parse(char *s) {
  return chknrmspace(s);
}
