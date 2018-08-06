#include "Floor.h"


void Floor::draw(sf::RenderWindow* window) {
	window->draw(*sprite);
}

Floor::Floor(float width, float height, float xpos, float ypos) :Object(floor1)
{
	this->width = width;
	this->height = height;
	texture->loadFromFile(floor1);
	sprite->setTexture(*texture);
	sprite->setScale(width / 300, height / 300);
	//sprite->setOrigin(sf::Vector2f(sprite->getGlobalBounds().width / 2, sprite->getGlobalBounds().height / 2));
	sprite->setPosition(xpos, ypos);
}

Floor::~Floor()
{
}
