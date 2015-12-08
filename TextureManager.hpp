#ifndef __TextureManager__
#define __TextureManager__

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <map>
#include <iostream>

class TextureManager {
private:
	static TextureManager* instance;
	std::map<std::string, SDL_Texture*> texture_map;
	TextureManager() {};
public:
	~TextureManager();
	static TextureManager* Instance() {
		if(!instance) {
			instance = new TextureManager();
			return instance;
		}
		return instance;
	}
	
	bool load(std::string, std::string, SDL_Renderer*);
	void draw(std::string, int, int, int, int, SDL_Renderer*, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void draw_frame(std::string, int, int, int, int, int, int, SDL_Renderer*, SDL_RendererFlip flip = SDL_FLIP_NONE);
};

#endif