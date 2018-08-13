#pragma once
#include "Widget.h"
#include <SFML/Graphics.hpp>
#include <vector>
class Screen
{
public:
	Screen(sf::RenderWindow &);
	virtual void  render();
	virtual void update();
	virtual Screen* checkEvents(); // Thinking about what this function should be doing. Might need to create another class that handles transitions between screens Sorta like intents in Java. 
	virtual void start();
private:
	std::vector<Widget>* _elements; 
	sf::RenderWindow * _window;
	~Screen();
};

