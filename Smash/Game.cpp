#include "Game.h"

Game::Game(sf::RenderWindow& window)
{
	//initialize players
	players = new vector<Player*>();

	player1 = new Player(key1, p1idle, &window);
	players->push_back(player1);
	player2 = new Player(key2, p2idle, &window);
	players->push_back(player2);

	font.loadFromFile("opensans.ttf");

	makeText(text, 800, 350);
	makeText(text2, 700, 150); //xpos,ypos of player
	makeText(text3, 600, 250); //xpos,ypos of floor 1
	makeText(text4, 150, 50); //num of projectiles
	makeText(text5, 150, 100); //jumped1
	makeText(text6, 150, 150); //jumped2
	makeText(text7, 150, 200); //isJumping
	//initalize stage
	stage = new Stage();
	stage->addFloor(400.f, 400.f, 200, 850);

	//long ass way of getting leftmost x, rightmost x, topmost y, bottommost y
	text2.setString("Floor: " + to_string(stage->getFloors()->at(0)->get_left_x()) + "," + to_string(stage->getFloors()->at(0)->get_right_x()) + " by " + to_string(stage->getFloors()->at(0)->get_top_y()) + "," + to_string(stage->getFloors()->at(0)->get_bottom_y()));
	
	this->window = &window;
	currentState = 0;
	start();
}

void Game::changeState(int state) {
	if (state != currentState) {
		currentState = state;
	}
}

void Game::checkCollision(Player* player, vector<Floor*>* floors) {
	//collision between player and all floors
	for (auto i : *floors) {

		text3.setString("Player: " + to_string(player->get_left_x()) + "," + to_string(player->get_right_x()) +
			" by " + to_string(player->get_top_y()) + "," + to_string(player->get_bottom_y()));

		text4.setString("Can Jump: " + to_string(player1->canJump()));
		text5.setString("Jumped1: " + to_string(player->getJumped1()));
		text6.setString("Jumped2: " + to_string(player->getJumped2()));
		text7.setString("IsJumping: " + to_string(player->getIsJumping()));

		player->checkFloorCollision(i);

	}
}

void Game::checkCollision(Projectile* projectile, vector<Floor*>* floors) {
	//collision between each projectile and all floors
	for (auto i : *floors) {
		projectile->checkFloorCollision(i);
	}
}
void Game::checkCollision(Player* player, vector<Projectile*>* projectiles) {
	for (int i = 0; i < projectiles->size(); i++) {
		if (player->isColliding(projectiles->at(i)) && player != projectiles->at(i)->getOwner()) {
			player->addHealth(projectiles->at(i)->getDamage());
			player->push_back(projectiles->at(i)->getDirection());
			projectiles->erase(projectiles->begin() + i);
		}
	}


}
void Game::checkCollisions(vector<Projectile*>* projectiles, vector<Floor*>* floors) {
	for (auto i : *projectiles) {
		checkCollision(i, floors);
	}

}
void Game::checkAllCollisions() { //checks all collisions specific interaction with collision
	for (auto i : *players) {
		checkCollision(i, stage->getFloors());
		//will add more for projectiles and such
		checkCollisions(i->getProjectiles(), stage->getFloors());
		for (auto j : *players) {
			checkCollision(i, j->getProjectiles());
		}
	}

}
void Game::checkEvents() { //only button presses and stuff
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) window->close();

		if (event.type == sf::Event::KeyPressed) {
			player1->checkPlayerButtons(event, true);
			player2->checkPlayerButtons(event, true);
		}

		if (event.type == sf::Event::KeyReleased) {
			player1->checkPlayerButtons(event, false);
			player2->checkPlayerButtons(event, false);
		}
	}

}
void Game::update() { //move movements or do things and stuff

	player1->update();
	player2->update(); //uncomment to update player2

}

void Game::render() { //only draws and stuff
	window->clear();
	/*window->draw(text);
	window->draw(text2);
	window->draw(text3);
	window->draw(text4);
	window->draw(text5);
	window->draw(text6);
	window->draw(text7);*/
	player1->draw(window);
	player2->draw(window);
	stage->draw(window);
	window->display();
}


void Game::start() {
	while (window->isOpen())
	{
		checkEvents();

		checkAllCollisions();

		update();

		render();
	}
}

void Game::makeText(sf::Text& text, int xpos, int ypos) {
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(xpos, ypos));
	text.setString("None seen yet...");
}

Game::~Game()
{
	delete player1;
	delete player2;
	delete stage;
}