#pragma once
#include "Textures.h"
#include <SFML\Graphics.hpp>
using namespace std;
class Object
{
protected:
	sf::Texture* texture;
	sf::IntRect* spritesheet;
	sf::Sprite* sprite;
	float sprite_height;
	float sprite_width;

public:
	Object(const char* textures);
	Object();

	virtual bool isColliding(Object* object);
	int checkCollisionDirection(Object* object);
	int checkCollisionDirectionX(Object* object);
	int checkCollisionDirectionY(Object* object);

	void setUpSpriteSheet();

	float get_left_x();
	float get_right_x();
	float get_top_y();
	float get_bottom_y();

	bool isAbove(Object* object);
	bool isBelow(Object* object);
	bool isLeftOf(Object* object);
	bool isRightOf(Object* object);
	sf::Sprite* getSprite();

	float getWidth();
	float getHeight();

	void place_on(Object* object); //places object above the object
	void place_right_of(Object* object); //places object right of object
	void place_left_of(Object* object); //places object left of object

	virtual void draw(sf::RenderWindow* window);
	virtual void update();
	~Object();
};

