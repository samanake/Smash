#include "Floor.h"


void Floor::draw(sf::RenderWindow* window) {
	window->draw(*sprite);
}

Floor::Floor(char_vector_t* textures, int* text_size, float width, 
	float height, float xpos, float ypos) :Object(textures, text_size)
{
	this->width = width;
	this->height = height;
	sprite->setScale(width / 300, height / 300);
	sprite->setPosition(xpos, ypos);
}

Floor::~Floor()
{
}
