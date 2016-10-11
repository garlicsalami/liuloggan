#include "bomb.h"

int Bomb::move(void)
{
	if (bombstate == LANDED)
		return 1;

	int y = this->getRect().y;
	if (y >= HEIGHT || y >= ground) {
		bombstate = LANDED;
		return CHANGEIMAGE; 
	}
	

	static int count = 0;
	if (count >= speed) {		
		Object::setRectY(y + 1);
		count = 0;
	}
	
	count++;

	return 0;			
}
