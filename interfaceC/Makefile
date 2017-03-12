# Makefile

CC=gcc

CPPFLAGS= `pkg-config --cflags --libs gtk+-3.0`
CFLAGS=   -std=c99 -lm -g #-O3
LDFLAGS=
LDLIBS= `pkg-config  --libs gtk+-3.0`

SRC= main.c ../parsing.c ../build_exp.c ../calculation.c
OBJ= ${SRC:.c=.o}

all: main

main:
	${CC} ${SRC} -o Interface ${CFLAGS} ${CPPFLAGS} 

clean:
	rm -f Interface
	rm -f *~ *.o

# END

