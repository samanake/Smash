#pragma once
#include "Physics.h"
#include "PlayerControls.h"
#include "PlayerBools.h"
#include "Object.h"
#include "Projectile.h"
#include <iostream>
using namespace std;
class Player : public Object, public PlayerBools
{
	//private declarations of variables, public function protyptes
private:
	int health; //in percentage
	sf::Keyboard::Key* keys;

	float xspeed; //speed in the x direction
	double xvelocity,yvelocity; //velocity in the x and y direction
	float jumpStr; //strength of jump

	vector<Projectile*>* projectiles;

	LifeSpan * cooldown;
	sf::RenderWindow * ref_window;
public:
	Player(sf::Keyboard::Key* keys, const char* textures, sf::RenderWindow * window);

	void attack();
	void checkPlayerButtons(sf::Event& event, bool cond);
	void setTextures(const char*textures);
	void setSprite();
	void update();
	void draw(sf::RenderWindow* window);
	void setXVelocity(float xVelocity);
	void setYVelocity(float yVelocity);
	float getXVelocity();
	float getYVelocity();
	void pause();
	void push_back(sf::Vector2f* direction); 

	void setLeft(bool cond);
	void setRight(bool cond);
	void setUp(bool cond);
	void setDown(bool cond);

	void addProjectile(Projectile* projectile);
	void updateProjectiles();
	void drawProjectiles(sf::RenderWindow* window);

	void checkCooldown();
	void checkFloorCollision(Object* floor);

	int getNumberOfProjectiles();
	vector<Projectile*>* getProjectiles();

	void addHealth(int health);

	~Player();
};

