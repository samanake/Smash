#pragma once
#include "Object.h"
class Floor : public Object
{
private:
	float width, height;
public:
	void draw(sf::RenderWindow* window);
	Floor(float width, float height, float xpos, float ypos);
	~Floor();
};

