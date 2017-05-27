struct context {
	char **func_name;
	int nbFunc;
	int *func_addr;
	char **var_name;
	int nbVar;
	int *var_addr;
};

char *key_words[] =
	{ "tanke",
		"if",
		"else"
		"var" };

char *build_in_functions_names[] =
	{ "print",
		"input"	};

int build_in_functions_addr[] =
	{ 0,
		1 };

int search_var(char **s, struct context *context);
