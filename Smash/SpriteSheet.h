#pragma once
#include <SFML/Graphics.hpp>
#include "LifeSpan.h"
#include "Physics.h"
class SpriteSheet {
private:
	sf::IntRect* rect;
	sf::Texture* texture;
	int width, height;
	int num; //number of sprites in the spritesheet
	int index;
	LifeSpan* rotation;
public:
	SpriteSheet(const char* filename, int num);
	sf::IntRect* getRect(int index);
	sf::Texture* getTexture();
	int getNum();
	int getIndex();
	void play();
	void stop();
	~SpriteSheet();
};