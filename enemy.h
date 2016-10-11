#ifndef ENEMY_H
#define ENEMY_H

#include "object.h"

class Enemy : public Object {
 public:
	
	Enemy(SDL_Renderer *renderer, const string &fp, SDL_Rect r)
		: Object(renderer, fp, r, ENEMY) {}	

	int move(void) { return 0; }

};

#endif //ENEMY_H
