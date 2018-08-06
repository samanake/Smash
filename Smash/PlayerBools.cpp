#include "PlayerBools.h"



PlayerBools::PlayerBools()
{
}

bool PlayerBools::canJump() { //true if jump is available and is not jumping
	return (!jumped1 || !jumped2) && !isJumping;
}

void PlayerBools::setJumpBools() { //sets jumped1 to true and sets jumped2 to true if jumped1 is true
	if (jumped1) jumped2 = true;
	else jumped1 = true;
	isJumping = true;
}

void PlayerBools::resetJumpBools() { //sets jumped1 and jumped2 to false
	jumped1 = false;
	jumped2 = false;
}

bool PlayerBools::getJumped1() { return jumped1; }

bool PlayerBools::getJumped2() { return jumped2; }

bool PlayerBools::getIsJumping() { return isJumping; }

