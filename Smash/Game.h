#pragma once
#include "Player.h"
#include "Stage.h"

class Game
{
private:
	int currentState; //0 is menu, 2 is battle
	sf::RenderWindow* window;

	vector<Player*>* players;
	Player *player1, *player2;
	Stage *stage;

	sf::Text text, text2, text3, text4, text5, text6, text7;
	sf::Font font;
public:
	Game(sf::RenderWindow& window);
	~Game();
	void changeState(int state);
	void start();
	void update();
	void render();
	void checkEvents();

	//collisions between specific Objects
	void checkCollision(Player* player, vector<Floor*>* floors);

	void checkCollisions(vector<Projectile*>* projectiles, vector<Floor*>* floors);
	void checkCollision(Projectile* projectile, vector<Floor*>* floors);
	void checkAllCollisions();
	void checkCollision(Player* player, vector<Projectile*>* projectiles);

	void makeText(sf::Text& text, int xpos, int ypos);
};

