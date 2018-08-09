#pragma once
#include "Object.h"
class Floor : public Object
{
private:
	float width, height;
public:
	void draw(sf::RenderWindow* window);
	Floor(char_vector_t* textures, int* text_size, float width,
		float height, float xpos, float ypos);
	~Floor();
};

