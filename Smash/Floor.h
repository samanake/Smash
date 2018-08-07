#pragma once
#include "Object.h"
class Floor : public Object
{
private:
	float width, height;
public:
	void draw(sf::RenderWindow* window);
	Floor(const char** textures, int* text_size, float width,
		float height, float xpos, float ypos);
	~Floor();
};

