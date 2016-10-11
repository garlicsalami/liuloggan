#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include "structs.h"

class Player : public Object {
 public:

	Player(SDL_Renderer *renderer)
		: Object(renderer, PLAYERIMG, { PLAYERSTARTX, PLAYERSTARTY, PLAYERWIDTH, PLAYERHEIGHT}, PLAYER) 
	{
		direction = RIGHT;
	}

	int move(void);

	void setRectX(int);
	void changeDirection(void);


 private:
	Direction direction;
};

#endif //PLAYER_H
