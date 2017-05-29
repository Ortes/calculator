# include <stdlib.h>
# include <string.h>
# include "char_macros.h"
# include "code_paring.h"

static inline void rmSpaces(char **s) {
	while (**s == ' ') (*s)++;
}

int cond(char **s; struct context *context) {
	rmSpaces(s);
	if (**s == '(') {
		(*s)++;
		cond(s, context);
	}
	if (IS_LETTER(**s)) {
		if ((int index = search_var) != -1)
	}
	return 0;
}

int tanke(char **s, struct context *context) {
	rmSpaces(s);
	cond(s, context);
	
	return 0;
}

int (*keyWFuncs[3])(char **s, struct context *context) =
{
	&tanke
};

void check_instruction(char **s, struct context *context) {
	int nb = 0;
	char *s2 = *s;
	int boolArrayKey[sizeof(key_words)]; // remplacer par la division !!!! sizeof(key_words) / sizeof(key_words[0])
	for (int i = 0; i < sizeof(key_words); i++) boolArrayKey[i] = 42;

	int seek = 0;
	while (nb) {
		for (int i = 0; i < sizeof(key_words); i++) {
			if (boolArrayKey[i]) {
				if (key_words[i][seek] != **s) {
					if (key_words[i][seek] == '\0') {
						(*keyWFuncs[i])(s, context);
					}
					boolArrayKey[i] = 0;
					nb--;
				}
			}
		}
		(*s)++;
		seek++;
	}

	*s = s2;
	nb = 0;
	seek = 0;
	int boolArrayFunc[context->nbFunc];
	for (int i = 0; i < context->nbFunc; i++) boolArrayFunc[i] = 42;
	
	while (nb) {
		for (int i = 0; i < context->nbFunc; i++) {
			if (boolArrayFunc[i]) {
				if (key_words[i][seek] != **s) {
					if (key_words[i][seek] == '\0') {
						// mettre des trucs la :D
					}
					boolArrayFunc[i] = 0;
					nb--;
				}
			}
		}
		seek++;
	}
}

int parsing(char *s) {
	struct context *context = malloc(sizeof(struct context));
	context->func_name = malloc(sizeof(char *) * sizeof(build_in_functions_names));
	for (int i = 0; i < sizeof(build_in_functions_names); i++)
		context->func_name[i] = build_in_functions_names[i];
	context->nbFunc;
	context->func_addr = malloc(sizeof(int) * sizeof(build_in_functions_names));
	memcpy(context->func_addr, build_in_functions_addr, sizeof(build_in_functions_names));
	while (*s) {
		check_instruction(&s, context);
	}
	for (int i = sizeof(build_in_functions_names); i < context->nbFunc; i++)
		context->func_name[i] = build_in_functions_names[i];
	free(context->func_name);
	free(context);
}
