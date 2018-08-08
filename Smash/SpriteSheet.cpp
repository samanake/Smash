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
	
	index = 0;
}

int SpriteSheet::getNum() { return num; }

int SpriteSheet::getIndex() { return index; }

sf::IntRect* SpriteSheet::getRect(int index) { return &rect[index]; }

void SpriteSheet::play() {
	if (rotation == NULL) {
		rotation = new LifeSpan(rotationSpeed*num);
	}
}

void SpriteSheet::stop() {
	if (rotation != NULL) delete rotation;
}

sf::Texture* SpriteSheet::getTexture() {
	return this->texture;
}

SpriteSheet::~SpriteSheet() {
	delete rect;
	delete texture;
	delete rotation;
}