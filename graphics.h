#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "structs.h"
#include "object.h"


class Graphics {
 public:

	~Graphics();
	
	int init(void);

	void renderObjects(const vector<Object*> &);	

	SDL_Renderer* getRenderer(void) const;
	SDL_Window* getWindow(void) const;

 private:
	SDL_Renderer *renderer;
	SDL_Window *window;
};

#endif
