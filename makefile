# Variables
CC = clang++
INCLUDE = -I include
LIBS = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
CFLAGSO = -std=c++20 -m64 -Wall -c ${INCLUDE}
CFLAGSB = -c ${LIBS}

# Target: Dependencies
#	Action

main: main.o
	${CC} bin/*.o -o build/main ${CFLAGSB}

main.o: src/main.cpp
	${CC} -c src/main.cpp ${CFLAGSO} -o ./bin/main.o

renderwindow.o: src/renderwindow.cpp
	${CC} -c src/renderwindow.cpp ${CFLAGSO} -o ./bin/renderwindow.o

clean:
	rm ./bin/*.o ./build/main
