#ifndef __GameObject__
#define __GameObject__

#include <SDL.h>
#include <string>
#include "TextureManager.hpp"

class GameObject {
protected:
	int x, y, w, h, current_frame, current_row;
	std::string texture_id;
	void load(int, int, int, int, std::string);
public:
	GameObject() {};

	virtual void draw(SDL_Renderer *);
	virtual void update() = 0;
	virtual void clean() = 0;
};

#endif