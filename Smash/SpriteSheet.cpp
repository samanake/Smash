#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(const char* filename, int num) {
	texture = new sf::Texture;
	texture->loadFromFile(filename);
	sf::Vector2u size = texture->getSize();
	rect = new sf::IntRect[num];
	width = size.x/num;
	height = size.y;
	for (int i = 0; i < num; i++) {
		rect[i] = sf::IntRect(i*width, 0, width, height);
	}
	this->num = num;
	index = 0;
}

int SpriteSheet::getNum() { return num; }

int SpriteSheet::getIndex() { return index; }

sf::IntRect* SpriteSheet::getRect() { return &rect[index]; }

void SpriteSheet::play() {
	index = 0;
	if (rotation == NULL) 
		rotation = new LifeSpan(rotationSpeed);
	else rotation->reset(rotationSpeed);
	isPlaying = true;
}

void SpriteSheet::update() {
	if (rotation != NULL) {
		if (rotation->hasEnded()) {
			if (index + 1 == num) {
				index = 0;
			}
			else index++;
			rotation->reset(rotationSpeed);
		}
	}
}

sf::Texture* SpriteSheet::getTexture() {
	return this->texture;
}

SpriteSheet::~SpriteSheet() {
	delete rect;
	delete texture;
	delete rotation;
}