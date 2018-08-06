#pragma once
#include "Floor.h"
class Stage
{
private:
	sf::Texture* background;
	sf::Sprite* backgroundSprite;
	vector<Floor*> floors;
public:
	Stage();
	void addFloor(float width, float height, float xpos, float ypos);
	void draw(sf::RenderWindow* window);
	~Stage();
	vector<Floor*>* getFloors();
};

