#pragma once
#include "Widget.h"
#include <SFML/Graphics.hpp>
#include <vector>
class Screen
{
public:
	Screen(sf::RenderWindow *);
	virtual void  draw();
	virtual void update();
	virtual void onClick();
private:
	std::vector<Widget>* _elements; 
	sf::RenderWindow * _window;
	~Screen();
};

