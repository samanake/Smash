#include "Screen.h"

Screen::Screen(sf::RenderWindow& window)
{
	this->_window = &window;
}

void Screen::render()
{
	for (auto i : *_elements) {
		// use window to draw all the UI elements. 
	}
}

	Screen* Screen::checkEvents()
{
	for (auto i : *_elements) {
		if (i.getView().getGlobalBounds().contains(sf::Mouse::getPosition(*_window))) {
			return i.getNextScreen();
		}
		//Create the Get View Function in widget.
		//Create getNextScreen which should return the next screen 
	}

}


