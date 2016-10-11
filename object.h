#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <vector>
using namespace std;

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "structs.h"


class Object {
 public:
	
	Object(SDL_Renderer *renderer, const string &filepath, SDL_Rect r, Id i);
	virtual ~Object();	
	
	void setRectX(int);
	void setRectY(int);

	void changeImage(SDL_Renderer *, const string &);

	virtual int move(void) = 0;

	SDL_Texture *getTexture(void) const;
	SDL_Rect getRect(void) const;
	Id getId(void) const;

 private:
	SDL_Texture *texture;
	SDL_Rect rect;

	Id id;
};

#endif //OBJECT_H
