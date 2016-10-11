#include "player.h"

int Player::move(void)
{
	int x = this->getRect().x;
	if (x <= 0-(PLAYERWIDTH/2) || x >= WIDTH-(PLAYERWIDTH/2))
		changeDirection();


	if (direction == LEFT)
		Object::setRectX(x - 1);
	else if (direction == RIGHT)
		Object::setRectX(x + 1);
		
	return 0;
}

void Player::changeDirection(void)
{
	if (direction == LEFT)
		direction = RIGHT;
	else
		direction = LEFT;
}


