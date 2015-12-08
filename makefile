OS := $(shell uname)

all:
ifeq ($(OS), Darwin)
	g++-5 -std=c++14 *.cpp -o game.out -I/Library/Frameworks/SDL2.framework/Headers -I/Library/Frameworks/SDL2_image.framework/Headers -framework SDL2 -framework SDL2_image -framework OpenGL -framework Cocoa
endif
ifeq ($(OS), Linux)
	g++ -std=c++11 *cpp -o game.out -I/usr/include/SDL2/ -lSDL2 -lSDL2_image
endif
