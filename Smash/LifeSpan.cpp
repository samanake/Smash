#include "LifeSpan.h"



LifeSpan::LifeSpan(int life)
{
	//life_ends_at = new sf::Int32(gameClock.getElapsedTime().asMilliseconds() + 
								 //sf::milliseconds(life).asMilliseconds());
	//life_ends_at = (int)gameClock.getElapsedTime().asMilliseconds() + sf::milliseconds(life).asMilliseconds();
	reset(life);
}

bool LifeSpan::hasEnded() {

	return (life_ends_at <= (int)gameClock.getElapsedTime().asMilliseconds());
}

void LifeSpan::reset(int life) {
	life_ends_at = (int)gameClock.getElapsedTime().asMilliseconds() + sf::milliseconds(life).asMilliseconds();
}

int LifeSpan::getLifeEnds() {
	return life_ends_at;
}

LifeSpan::~LifeSpan()
{
	//delete life_ends_at;
}
