#include <SDL.h>
#include "game.hpp"

using namespace std;

Game *game = 0;

int main( int argc, char* args[] ) {

	game = new Game("Hello World!");

	while(game->is_running()) {
		game->handle_events();
		game->update();
		game->render();
	}

	delete game;

	return 0;
}