#include "GameObject.hpp"

void GameObject::load(int x_pos, int y_pos, int width, int height, std::string id) {
	x = x_pos;
	y = y_pos;
	h = height;
	w = width;
	texture_id = id;
	current_frame = current_row = 1;
}

void GameObject::draw(SDL_Renderer * renderer) {
	TextureManager::Instance()->draw_frame(texture_id, x, y, w, h, current_row, current_frame, renderer);
}