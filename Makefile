CC=gcc
CPPFLAGS=
CFLAGS= -Wall -Wextra -std=c99 -g
LDFLAGS=
LDLIBS=

SRC = *.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

all: main

main: ${OBJ}

-include ${DEP}

clean:
	rm -f ${OBJ} ${DEP}
	rm -f main
