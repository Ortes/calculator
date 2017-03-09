# define S_BEGIN 0
# define S_NUMBER 1
# define S_DECIMAL_NUMBER 2
# define S_OPERATOR 3
# define S_LETTER 4
# define S_SQRT 5
# define S_EXP 5
# define S_LOG 5

# define T_CALC 0
# define T_FUNCTION 1

# define IS_SPACES(_CHAR) _CHAR == ' ' || _CHAR == '\t'
# define IS_LETTER(_CHAR) (_CHAR >= 'a' && _CHAR <= 'z') || (_CHAR >= 'A' && _CHAR <= 'Z')
# define IS_NUMBER(_CHAR) _CHAR >= '0' && _CHAR <= '9'
# define IS_OPERATOR(_CHAR) _CHAR == '+' || _CHAR == '-' || _CHAR == '*' || _CHAR == '/' || _CHAR == '^'

int chknrmspace(char *s) {
  static char *sqrt = "sqrt";
  int state = S_BEGIN;
  int type = T_CALC;
  int pos_in_func_def = 0;
  
  for (; *s; ++s) {
    switch (state) {
      
    case S_BEGIN :
      if (IS_NUMBER(*s))
	state = S_NUMBER;
      else if (IS_LETTER(*s))
	state = S_LETTER;
      else if (IS_SPACES(*s))
	break;
      else
	return -1;
      break;
      
    case S_NUMBER :
      if (IS_NUMBER(*s))
	break;
      else if (*s == '.')
	state = S_DECIMAL_NUMBER;
      else if (IS_SPACES(*s))
	state = S_OPERATOR;
      else
	return -1;
      break;

    case S_DECIMAL_NUMBER :
      if (IS_NUMBER(*s))
	break;
      else if (IS_SPACES(*s))
	state = S_OPERATOR;
      else if (IS_OPERATOR(*s))
	state = S_NUMBER;
      else
	return -1;
      break;

    case S_OPERATOR :
      if (IS_SPACES(*s))
	break;
      else if(IS_OPERATOR(*s))
	state = S_NUMBER;
      else
	return -1;

    case S_LETTER :
      if (IS_LETTER(*s))
	break;
      else if (IS_SPACES(*s))
	state = S_OPERATOR;
      else if (IS_OPERATOR(*s))
	state = S_NUMBER;
      else
	return -1;
      
    case S_SQRT :
      if (sqrt[pos_in_func_def] == *s) {
	pos_in_func_def++;
	break;
      }
      if (!sqrt[pos_in_func_def]) {
	if (IS_SPACES(*s))
	  break;
	if (*s == '(')
	  state = S_NUMBER;
      }
      if (IS_NUMBER(*s))
	return -1;
      else if (IS_SPACES(*s))
	state = S_OPERATOR;
      else if (IS_OPERATOR(*s))
	state = S_NUMBER;
      else
	return -1;
      break;

    default :
      break;
    }
  }
  return type;
}

int parse(char *s) {
  return chknrmspace(s);
}
