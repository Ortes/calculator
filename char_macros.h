# define IS_SPACES(_CHAR) (_CHAR == ' ' || _CHAR == '\t')
# define IS_LETTER(_CHAR) ((_CHAR >= 'a' && _CHAR <= 'z') || (_CHAR >= 'A' && _CHAR <= 'Z'))
# define IS_NUMBER(_CHAR) (_CHAR >= '0' && _CHAR <= '9')
# define IS_OPERATOR(_CHAR) (_CHAR == '+' || _CHAR == '-' || _CHAR == '*' || _CHAR == '/' || _CHAR == '^')
