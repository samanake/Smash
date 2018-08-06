#pragma once
class PlayerBools
{
protected:
	bool up = false, down = false, left = false, right = false; //movement
	bool isPaused = false; //checking pause

	bool jumped1 = false; //single jump
	bool jumped2 = false; //double jump
	bool isJumping = false; //only true when up is pressed

	bool projectileFired = false;
public:
	PlayerBools();

	bool canJump();
	void setJumpBools();
	void resetJumpBools();

	bool getJumped1();
	bool getJumped2();
	bool getIsJumping();

};

