#include "Player.h"
using namespace std;
//the player is given its own vector of projectiles. When a player is killed, its projectiles slowly fade/are deleted along with the players.
Player::Player(sf::Keyboard::Key* keys, const char* textures, sf::RenderWindow * window) :Object(textures)
{
	this->keys = keys;
	this->ref_window = window;
	health = 0;
	xspeed = 1.f;
	xvelocity = 0;
	yvelocity = 0;
	jumpStr = -2.f;
	setTextures(textures);
	setSprite(); //initializes sprite to 0th texture

	projectiles = new vector<Projectile*>();
	cooldown = 0;
}

void Player::setTextures(const char* textures) {
	if (texture->loadFromFile(textures)) {
	}
}

void Player::setSprite() {
	sprite->setTexture(*texture);
}

void Player::attack() {

}

void Player::checkPlayerButtons(sf::Event& event, bool cond) {
	if (event.key.code == keys[0]) { //up
		if (canJump()) {
			setJumpBools();
			sprite->setPosition(sprite->getPosition().x, sprite->getPosition().y - 1);
			yvelocity = jumpStr;
		}
		if (!cond) isJumping = false; //if up key is let go, they can jump again

	}
	if (event.key.code == keys[1]) { //left
		left = cond;
	}
	if (event.key.code == keys[2]) { //down
		down = cond;
	}
	if (event.key.code == keys[3]) { //right
		right = cond;
	}
	if (event.key.code == keys[4]) {
		projectileFired = cond;
	}
}

void Player::update() {
	sf::Vector2f movement(0.f, 0.f);
	//if (left) movement.x -= xspeed;
	//if (right) movement.x += xspeed;

	if (left && xvelocity >= -xspeed) xvelocity -= xspeed;
	else if (right && xvelocity <= xspeed) xvelocity += xspeed;
	else if (xvelocity >= 0) xvelocity -= .2f;
	else if (xvelocity <= 0) xvelocity += .2f;
	movement.x = xvelocity;
	movement.y = yvelocity;
	sprite->move(movement);

	yvelocity += gravity;

	updateProjectiles();
}

void Player::checkFloorCollision(Object* floor) { //interacts with collision between player and all floors
	if (!this->isColliding(floor)) {
		this->jumped1 = true;
		return;
	}

	int check = checkCollisionDirection(floor);
	if ((check & 0x1)) { //"player on top"
		setYVelocity(0);

		//first checking if any collision between projectile and floors

		this->place_on(floor);
		this->resetJumpBools();
	}
	if (check >> 3 & 0x1) { //"player below"
		setYVelocity(.5);
	}
	if (check >> 2 & 0x1) {
		setLeft(false); //collision on the left side of the player
		this->place_right_of(floor);
	}
	if (check >> 1 & 0x1) { //collision on the Right side of the player
		setRight(false);
		this->place_left_of(floor);
	}
}

void Player::pause() { //this would be called if player was stunned or something

}
void Player::push_back(sf::Vector2f* direction) { //like smash, hits or projectiles send players backwards
	/*if ((direction->x > 0 && xvelocity < 0) || (direction->x < 0 && xvelocity > 0)) {
		xvelocity = -xvelocity;
	}
	if ((direction->y > 0 && yvelocity < 0) || (direction->y < 0 && yvelocity > 0)) {
		yvelocity = -yvelocity;
	}*/
	xvelocity += direction->x*health*damageFactor;
	yvelocity += direction->y*health*damageFactor;
}

void Player::addProjectile(Projectile* projectile) { //whenever a key is pressed projectile is added and launched
	projectiles->push_back(projectile);
}

void Player::updateProjectiles() { //moves their respective sprites
	//adding projectile
	if (projectileFired)
		addProjectile(new Projectile(projectile1, this, 5.0f, 2000, 10, ref_window));

	//updating projectiles
	for (int i = 0; i < projectiles->size(); i++) {
		(projectiles->at(i))->update();

		//deleting if dead
		if ((projectiles->at(i))->isDead()) {
			projectiles->erase(projectiles->begin() + i);

		}

	}
}

void Player::drawProjectiles(sf::RenderWindow* window) { //draws all projectiles' sprites
	for (auto i : *projectiles) {
		i->draw(window);
	}
}

void Player::draw(sf::RenderWindow* window) {
	window->draw(*sprite);
	drawProjectiles(window);
}

void Player::setLeft(bool cond) { left = cond; }
void Player::setRight(bool cond) { right = cond; }
void Player::setUp(bool cond) { up = cond; }
void Player::setDown(bool cond) { down = cond; }
void Player::setXVelocity(float xvelocity) { this->xvelocity = xvelocity; }
void Player::setYVelocity(float yvelocity) { this->yvelocity = yvelocity; }
float Player::getXVelocity() { return xvelocity; }
float Player::getYVelocity() { return yvelocity; }


int Player::getNumberOfProjectiles() { return projectiles->size(); }

vector<Projectile*>* Player::getProjectiles() { return projectiles; }

void Player::addHealth(int health) { this->health += health; }

Player::~Player() {
	for (auto i : *projectiles) {
		delete i;
	}
	delete projectiles;
}