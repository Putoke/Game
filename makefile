all:
	g++-5 -std=c++14 *.cpp -o game -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework OpenGL -framework Cocoa