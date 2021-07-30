# Variables
CC := clang++
INCLUDE := -I include
LIBS := -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
CFLAGSO := -std=c++20 -m64 -Wall -g $(INCLUDE)
CFLAGSB := $(LIBS)

EXEC_FILE := ./build/main

# Target: Dependencies
#	Action

$(EXEC_FILE): ./bin/main.o ./bin/config.o ./bin/entity.o ./bin/game.o ./bin/inputhandler.o ./bin/math.o ./bin/menu.o ./bin/player.o ./bin/renderwindow.o ./bin/world.o
	$(CC) ./bin/*.o -o ./build/main $(CFLAGSB)

./bin/main.o: src/main.cpp
	$(CC) -c src/main.cpp $(CFLAGSO) -o ./bin/main.o

./bin/renderwindow.o: src/renderwindow.cpp
	$(CC) -c src/renderwindow.cpp $(CFLAGSO) -o ./bin/renderwindow.o

./bin/config.o: src/config.cpp
	$(CC) -c src/config.cpp $(CFLAGSO) -o ./bin/config.o

./bin/entity.o: src/entity.cpp
	$(CC) -c src/entity.cpp $(CFLAGSO) -o ./bin/entity.o

./bin/game.o: src/game.cpp
	$(CC) -c src/game.cpp $(CFLAGSO) -o ./bin/game.o

./bin/inputhandler.o: src/inputhandler.cpp
	$(CC) -c src/inputhandler.cpp $(CFLAGSO) -o ./bin/inputhandler.o

./bin/math.o: src/math.cpp
	$(CC) -c src/math.cpp $(CFLAGSO) -o ./bin/math.o

./bin/menu.o: src/menu.cpp
	$(CC) -c src/menu.cpp $(CFLAGSO) -o ./bin/menu.o

./bin/player.o: src/player.cpp
	$(CC) -c src/player.cpp $(CFLAGSO) -o ./bin/player.o

./bin/world.o: src/world.cpp
	$(CC) -c src/world.cpp $(CFLAGSO) -o ./bin/world.o

clean:
	rm ./bin/*.o ./build/main
