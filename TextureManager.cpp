#include "TextureManager.hpp"

TextureManager* TextureManager::instance = 0;

TextureManager::~TextureManager() {
	for(auto it = texture_map.begin(); it != texture_map.end(); ++it) {
		SDL_DestroyTexture(it->second);
	}
}

bool TextureManager::load(std::string file_name, std::string id, SDL_Renderer* renderer) {
	SDL_Surface* temp_surface = IMG_Load(file_name.c_str());
	if(!temp_surface) {
		std::cout << "Could not load image surface: " << IMG_GetError() << std::endl;
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
	SDL_FreeSurface(temp_surface);
	if(!texture) {
		std::cout << "Could not create texture: " << SDL_GetError() << std::endl;
		return false;
	}

	texture_map[id] = texture;
	return true;
}

void TextureManager::draw(std::string id, int x, int y, int w, int h, SDL_Renderer* renderer, SDL_RendererFlip flip) {
	SDL_Rect src_rect, dst_rect;
	src_rect.x = src_rect.y = 0;
	src_rect.w = dst_rect.w = w;
	src_rect.h = dst_rect.h = h;
	dst_rect.x = x;
	dst_rect.y = y;
	SDL_RenderCopyEx(renderer, texture_map[id], &src_rect, &dst_rect, 0, 0, flip);
}

void TextureManager::draw_frame(std::string id, int x, int y, int w, int h, int current_row, int current_frame, SDL_Renderer * renderer, SDL_RendererFlip flip) {
	SDL_Rect src_rect, dst_rect;
	src_rect.x = w * (current_frame - 1);
	src_rect.y = h * (current_row - 1);
	src_rect.w = dst_rect.w = w;
	src_rect.h = dst_rect.h = h;
	dst_rect.x = x;
	dst_rect.y = y;
	SDL_RenderCopyEx(renderer, texture_map[id], &src_rect, &dst_rect, 0, 0, flip);
}