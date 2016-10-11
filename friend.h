#ifndef FRIEND_H
#define FRIEND_H

#include "object.h"

class Friend : public Object {
 public:
	
	Friend(SDL_Renderer *renderer, const string &fp, SDL_Rect r)
		: Object(renderer, fp, r, FRIEND) {}

	int move(void) { return 0; }
};

#endif //FRIEND_H
