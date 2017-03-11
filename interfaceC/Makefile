# Makefile

CC=gcc

CPPFLAGS= `pkg-config --cflags --libs gtk+-3.0`
CFLAGS=   -std=c99 -lm -g #-O3
LDFLAGS=
LDLIBS= `pkg-config  --libs gtk+-3.0`

SRC=
OBJ= ${SRC:.c=.o}

all: 
        
clean:
	rm -f *~ *.o

# END

