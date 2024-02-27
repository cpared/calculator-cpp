CFLAGS = -lSDL2 -lSDL2_ttf

build:
	g++ src/*.cpp ${CFLAGS} -o out/main

run:
	./out/main