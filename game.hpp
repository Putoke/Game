#ifndef __Game__
#define __Game__

#include <SDL.h>
#include <iostream>
#include <vector>
#include "TextureManager.hpp"
#include "player.hpp"

class Game {
private:
	bool running;
	SDL_Window * window;
	SDL_Renderer * renderer;
	std::vector<GameObject*> game_objects;
public:
	Game() {}
	Game(const char *);
	~Game();

	bool init(const char *, int xpos = SDL_WINDOWPOS_CENTERED, int ypos = SDL_WINDOWPOS_CENTERED, int width = 800, int height = 600, int flags = SDL_WINDOW_SHOWN);
	void handle_events();
	void update();
	void render();
	void clean();

	bool is_running() {return running;}
};

#endif