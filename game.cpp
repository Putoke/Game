#include "game.hpp"

Game::Game(const char * title) {
	init(title);
}

Game::~Game() {
	clean();
}

bool Game::init(const char * title, int xpos, int ypos, int width, int height, int flags) {
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if(window != 0) {
			renderer = SDL_CreateRenderer(window, -1, 0);
			if(renderer != 0) {
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			} else {
				std::cout << "Renderer initialization failed." << std::endl;
				return false;
			}
		} else {
			std::cout << "Window initialization failed." << std::endl;
			return false;
		}
	} else {
		std::cout << "SDL initialization failed." << std::endl;
		return false;
	}

	running  = true;
	return true;
}

void Game::handle_events() {
	SDL_Event event;
	if(SDL_PollEvent(& event)) {
		switch(event.type) {
			case SDL_QUIT:
				running = false;
				break;
			default:
				break;
		}
	}
}

void Game::update() {
	
}

void Game::render() {
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}