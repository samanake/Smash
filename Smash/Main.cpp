#include <iostream>
#include "Window.h"
#include "Game.h"


using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Upvote for Ronnieeeeee");
	Game* game = new Game(window);

	return 0;
}