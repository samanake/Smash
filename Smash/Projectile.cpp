#include "Projectile.h"

Projectile::Projectile(char_vector_t* textures, int* text_size, Object* owner, double velocity, int lifespan, 
						int damage, sf::RenderWindow * window) :Object(textures, text_size)
{
	this->owner = owner;
	sf::Vector2i mouse = sf::Mouse::getPosition(*window);
	sf::Vector2f object_pos = owner->getSprite()->getPosition();
	sprite->setPosition(object_pos);
	sprite->setScale(1.5f, 1.5f);
	direction = new sf::Vector2f();
	float xdirection = mouse.x - object_pos.x;
	float ydirection = mouse.y - object_pos.y;
	angle = atan2f(ydirection, xdirection);
	float degrees = angle * (180.0 / 3.141592653589793238463)+90;
	sprite->setRotation(degrees);

	direction->x = cos(angle);
	direction->y = sin(angle);

	this->velocity = velocity;
	drag = .02;
	

	this->lifespan = new LifeSpan(lifespan);

	this->damage = damage;
}

void Projectile::update() {
	sf::Vector2f movement(0.f, 0.f);
	movement.x = direction->x*velocity;
	movement.y = direction->y*velocity;
	sprite->move(movement);
	//if (checkOutOfBounds()) {
		//delete this;
	//}
	if (velocity > 0) velocity -= drag;
	
	play_spritesheet();
}

void Projectile::checkFloorCollision(Object* floor) { //checks collision between projectile and all floors.

	if (!this->isColliding(floor)) return; //check if colliding or not first

	//projectiles are reflected off of the floor

	int check = checkCollisionDirection(floor);
	if ((check & 0x1)) { //"projectile on top"
		negate_y_direction();
		this->place_on(floor);
	}
	if (check >> 3 & 0x1) { //"projectile below"
		negate_y_direction();
	}
	if (check >> 2 & 0x1) {
		negate_x_direction();
		this->place_right_of(floor);
	}
	if (check >> 1 & 0x1) { //collision on the Right side of the projectile
		negate_x_direction();
		this->place_left_of(floor);
	}
}

void Projectile::negate_x_direction() {
	direction->x = -direction->x;
}
void Projectile::negate_y_direction() {
	direction->y = -direction->y;
}


bool Projectile::checkOutOfBounds() {
	if (sprite->getPosition().x <= -20 && sprite->getPosition().x >= WIDTH + 20) {
		return true;
	}
	if (sprite->getPosition().y <= -20 && sprite->getPosition().x >= HEIGHT + 20) {
		return true;
	}
	return false;
}
bool Projectile::isDead() {
	return lifespan->hasEnded();
}
int Projectile::getDamage() {
	return damage;
}
Object* Projectile::getOwner() {
	return owner;
}
sf::Vector2f* Projectile::getDirection() {
	return direction;
}
Projectile::~Projectile()
{
	delete direction;
	delete lifespan;

}
