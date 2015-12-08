#include "player.hpp"

void Player::update() {
	current_frame = int(((SDL_GetTicks() / 120) % 4)) + 1;
	++x;
}

void Player::clean() {

}