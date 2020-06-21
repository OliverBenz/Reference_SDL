CC = gcc
SDLFLAGS = `sdl2-config --cflags --libs`

ALL: main

main: main.c player.o eventHandler.o
	${CC} main.c player.o eventHandler.o -o main ${SDLFLAGS}

player.o: player.c player.h
	${CC} -c player.c ${SDLFLAGS}

eventHandler.o: eventHandler.c eventHandler.h
	${CC} -c eventHandler.c ${SDLFLAGS}

make clean:
	rm main *.o
