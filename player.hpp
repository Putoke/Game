#ifndef __Player__
#define __Player__

#include "GameObject.hpp"

class Player : public GameObject{
public:
	Player() {}
	Player(int x, int y, int w, int h, std::string id) {GameObject::load(x, y, w, h, id);}

	virtual void update();
	virtual void clean();
	
};

#endif