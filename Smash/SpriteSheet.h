#pragma once
#include <SFML/Graphics.hpp>
class SpriteSheet {
private:
	sf::IntRect* rect;
	sf::Texture* texture;
	int width, height;
	int num; //number of sprites in the spritesheet
	int index;
public:
	SpriteSheet(const char* filename, int num);
	sf::IntRect* getRect(int index);
	sf::Texture* getTexture();
	int getNum();
	int getIndex();
	~SpriteSheet();
};