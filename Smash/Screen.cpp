#include "Screen.h"

Screen::Screen(sf::RenderWindow& window)
{
	this->_window = &window;
}

void Screen::draw()
{
	for (auto i : *_elements) {
		// Make Draw function
	}
}
