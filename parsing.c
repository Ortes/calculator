# include "parsing.h"

# define FUNCTION_NUMBER sizeof (funcs) / sizeof (*funcs)

char *chknrmspace(char *s) {
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
  
  int state = S_EXP_START;
  //int type = T_CALC;
  int parentesis = 0;

  char *dst;
  size_t i = 0;
  for (dst = s; *dst; dst++) i++;
  dst = malloc((i + 1) * sizeof(char));
  i = 0;
  
  for (; *s; s++) {
    dst[i] = *s;
    i++;
    if (IS_SPACES(*s)) {
      i--;
      continue;
    }

    else if (IS_NUMBER(*s)) {
      if (state != S_OPERATOR && state != S_EXP_START && state != S_NUMBER && state != S_DECIMAL_NUMBER)
	return NULL;
      state = S_NUMBER;
    }

    else if (*s == '.') {
      if (state == S_NUMBER)
	state = S_DECIMAL_NUMBER;
      else
	return NULL;
    }

    else if (IS_OPERATOR(*s)) {
      if (state != S_NUMBER && state != S_LETTER)
	return NULL;
      state = S_OPERATOR;
    }
    
    else if (IS_LETTER(*s)) {
      if (state != S_OPERATOR && state != S_EXP_START && state != S_LETTER)
	return NULL;
      state = S_LETTER;
      if (pos_in_func_def == 0 && !IS_LETTER(*(s + 1)))
	continue;
      for (size_t i = 0; i < FUNCTION_NUMBER; i++) {
	if (is_func[i] && funcs[i][pos_in_func_def] != *s) {
	  if (funcs[i][pos_in_func_def]) {
	    is_func[i] = 0;
	    nb_func_left--;
	  }
	  else
	    state = S_FUNC;
	} else if (is_func[i] && funcs[i][pos_in_func_def + 1] == '\0'){
	  state = S_FUNC;
	  for (size_t i = 0; i < FUNCTION_NUMBER; i++) is_func[i] = 1;
	  pos_in_func_def = -1;
	  nb_func_left = FUNCTION_NUMBER;
	  break;
	}
      }
      if (nb_func_left <= 0)
	return NULL;
      pos_in_func_def++;
    }

    else if (*s == '(') {
      if (state != S_OPERATOR && state != S_FUNC)
	return NULL;
      parentesis++;
      state = S_EXP_START;
    }
    
    else if (*s == ')') {
      if (state != S_NUMBER && state != S_LETTER)
	return NULL;
      parentesis--;
      if (parentesis < 0)
	return NULL;
    }

    else
      return NULL;
  }
  dst[i] = 0;
  return dst;
}

struct tree *parse(char *s) {
  char * cs = chknrmspace(s);
  if (!cs)
    return null;
  return build_exp(cs);
}
