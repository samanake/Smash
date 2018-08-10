#pragma once
#include "Object.h"
#include <math.h>
#include "Window.h"
#include "LifeSpan.h"
class Projectile : public Object
{
private:
	Object * owner;
	sf::Vector2f* direction;
	double velocity, drag;
	float angle;
	LifeSpan* lifespan; //lifespan left
	int damage;
public:
	Projectile(char_vector_t* textures, int* text_size, Object* object,
		double velocity, int lifespan, int damage, sf::RenderWindow * window);
	void checkFloorCollision(Object* floor);
	void update();
	bool checkOutOfBounds();
	bool isDead();
	void negate_x_direction();
	void negate_y_direction();

	int getDamage();
	Object* getOwner();
	sf::Vector2f* getDirection();
	~Projectile();
};

