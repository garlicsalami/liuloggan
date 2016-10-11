#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "object.h"

class Background : public Object {
 public:
	Background(SDL_Renderer *renderer)
		: Object(renderer, BACKGROUNDIMG, {1,3,3,7}, BACKGROUND) {}

	int move(void) { return 0; }
};

#endif //BACKGROUND_H
