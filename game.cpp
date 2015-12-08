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
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if(renderer != 0) {
				SDL_SetRenderDrawColor(renderer, 0, 55, 145, 255);
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

	//Testing texture mananger
	TextureManager::Instance()->load("spritelib_gpl/platform/arc1.png", "test", renderer);

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
	TextureManager::Instance()->draw("test", 0, 0, 640, 400, renderer);
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}