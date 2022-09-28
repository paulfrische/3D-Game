LIBS = -lGL -lGLEW -lglfw
CFLAGS = -o build/run
SRC = $(wildcard ./src/*.cpp)
CC = g++

all:
	mkdir -p build
	$(CC) $(SRC) $(CFLAGS) $(LIBS)

run: all
	./build/run
