#include "Stage.h"



Stage::Stage()
{
	background = new sf::Texture;
	background->loadFromFile("");
	backgroundSprite = new sf::Sprite;
	backgroundSprite->setTexture(*background);
}

void Stage::addFloor(float width, float height, float xpos, float ypos) {
	Floor* floor = new Floor(width, height, xpos, ypos);
	floors.push_back(floor);
}
void Stage::draw(sf::RenderWindow* window) {
	window->draw(*backgroundSprite);
	for (auto i : floors) {
		window->draw(*(i->getSprite()));
	}
}

Stage::~Stage()
{
}

vector<Floor*>* Stage::getFloors() {
	return &floors;
}