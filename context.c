# include "context.h"

# define GET_INDEX(_CHAR) _CHAR < 'a' ? _CHAR - '0' + 26 : _CHAR - 'a'

int search_tree(char **s, struct tree *t) {
	if(!**s)
		return 
	int index = GET_INDEX(**s);
	if (!t->bool[index])
		return -1;
	(*s)++;
	return search_tree(s, t[index]);
}

int search_var(char **s, struct context *context) {
	
}
