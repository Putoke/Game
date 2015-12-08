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
	//Testing player class
	TextureManager::Instance()->load("spritelib_gpl/platform/arc2.png", "test", renderer);
	Player * player = new Player(0, 100, 34, 42, "test");
	game_objects.push_back(player);
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
	for(auto it = game_objects.begin(); it != game_objects.end(); ++it) {
		(*it)->update();
	}
}

void Game::render() {
	SDL_RenderClear(renderer);
	for(auto it = game_objects.begin(); it != game_objects.end(); ++it) {
		(*it)->draw(renderer);
	}
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}