CC=gcc
CPPFLAGS=
CFLAGS= -Wall -Wextra -std=c99 -g
LDFLAGS=
LDLIBS=

SRC = main.c build_exp.c calculation.c parsing.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

all: main

main: ${OBJ}

-include ${DEP}

clean:
	rm -f ${OBJ} ${DEP}
	rm -f main
