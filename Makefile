CC=gcc
CFLAGS=-Iinclude -I/opt/homebrew/opt/raylib/include
LDFLAGS=-L/opt/homebrew/opt/raylib/lib -lraylib
SRC=src/main.c src/player.c src/utils.c src/projectile.c src/game.c
TARGET=survivors

default: all

all:
	${CC} ${SRC} ${CFLAGS} ${LDFLAGS} -o ${TARGET} 

run: all
	./${TARGET}

clean:
	rm -f ${TARGET}
