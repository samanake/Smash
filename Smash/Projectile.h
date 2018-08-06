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
	float velocity, drag;
	LifeSpan* lifespan; //lifespan left
	int damage;
public:
	Projectile(const char* textures, Object* object,
		float velocity, int lifespan, int damage, sf::RenderWindow * window);
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

