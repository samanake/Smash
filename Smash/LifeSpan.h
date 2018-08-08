#pragma once
#include "GlobalClock.h"
class LifeSpan
{
	//the lifespan class is passed in a life in int, which represents milliseconds
	//life_ends_at represents the time in which the life span would end respective to the clock
	//there is one method that checks if life_ends_at is shorter than the clock's time
	//in that case, the lifespan has been reached, and the object should die
protected:
	//sf::Int32* life_ends_at; //a certain time in the clock that the lifespan ends
	int life_ends_at;
public:
	LifeSpan(int life);

	bool hasEnded();

	//sf::Int32* getLifeEnds();
	int getLifeEnds();
	void reset(int life);

	~LifeSpan();
};

