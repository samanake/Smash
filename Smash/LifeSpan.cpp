#include "LifeSpan.h"



LifeSpan::LifeSpan(int life)
{
	life_ends_at = new sf::Int32(gameClock.getElapsedTime().asMilliseconds() + 
								 sf::milliseconds(life).asMilliseconds());
}

bool LifeSpan::hasEnded() {

	return (*life_ends_at <= gameClock.getElapsedTime().asMilliseconds());
}

sf::Int32* LifeSpan::getLifeEnds() {
	return life_ends_at;
}

LifeSpan::~LifeSpan()
{
	delete life_ends_at;
}
