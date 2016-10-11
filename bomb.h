#ifndef BOMB_H
#define BOMB_H

#include "object.h"
#include <random>

class Bomb : public Object {
 public:

	Bomb(SDL_Renderer *renderer, SDL_Rect r)
		: Object(renderer, FALLINGBOMB, r, BOMB) 
	{
		random_device rnd;

		int max = HEIGHT-BOMBHEIGHT-10;
		int min = HEIGHT-(ENEMYHEIGHT);
		ground = rnd() % (max-min + 1) + min;

		speed = SLOW;
		bombstate = FALLING;
	}	

	int move(void);

 private:
	int ground;
	Bombstate bombstate;
	Speed speed;
};

#endif //BOMB_H
