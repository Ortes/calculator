#ifndef PARSING_H_
#define PARSING_H_

int parse(char *s);

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


#endif
