
# define S_BEGIN 0
# define S_NUMBER 1
# define S_DECIMAL_NUMBER 2
# define S_OPERATOR 3
# define S_LETTER 4

# define T_CALC 0

static inline void rmextraspace(char *s) {
  for (; *s == '\t' || *s == ' '; ++s);
}

int chknrmspace(char *s) {
  int state = S_BEGIN;
  int type = T_CALC;
  
  for (s = s; *s; ++s) {
    switch (state) {
      
    case S_BEGIN :
      rmextraspace(s);
      if (*s >= '0' || *s <= '9')
	state = S_NUMBER;
      else if (*s >= 'a' || *s <= 'z')
	state = S_LETTER;
      else if (*s >= 'A' || *s <= 'Z')
	state = S_LETTER;
      else
	return -1;
      break;
      
    case S_NUMBER :
      if (*s >= '0' || *s <= '9')
	break;
      else if (*s == '.') {
	state = S_DECIMAL_NUMBER;
	break;
      }
      else if (*s == ' ') {
	rmextraspace(s--);
	state = S_OPERATOR;
	break;
      }
      else
	return -1;
	
    default :
      break;
    }
  }
  return type;
}

int parse(char *s) {
  chknrmspace(s);
  return 0;
}
