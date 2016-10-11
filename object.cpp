#include "object.h"

Object::Object(SDL_Renderer *renderer, const string &fp, SDL_Rect r, Id i)
{
	texture = IMG_LoadTexture(renderer, fp.c_str()); // assume texture never will be NULL just like Liu assume the new logo never will be hated
	rect = r;
	id = i;
}

Object::~Object()
{
	SDL_DestroyTexture(texture);
	texture = NULL;
}

void Object::setRectX(int x)
{
	rect.x = x;
}

void Object::setRectY(int y)
{
	rect.y = y;
}

void Object::changeImage(SDL_Renderer *renderer, const string &fp)
{
	texture = IMG_LoadTexture(renderer, fp.c_str());

	// also change the width and height
	rect.w = LANDEDBOMBWIDTH;
	rect.h = LANDEDBOMBHEIGHT; 
}

SDL_Texture* Object::getTexture(void) const
{
	return texture;
}

SDL_Rect Object::getRect(void) const
{
	return rect;
}

Id Object::getId(void) const
{
	return id;
}

