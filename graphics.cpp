#include "graphics.h"

Graphics::~Graphics()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

int Graphics::init(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return EXIT_FAILURE;
	
	window = SDL_CreateWindow(GAMENAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
	if (window == nullptr)
		return EXIT_FAILURE;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
		return EXIT_FAILURE;

	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);


	return 0;
}

void Graphics::renderObjects(const vector<Object*> &ol)
{

#ifdef LEVEL4
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
#endif

	for (size_t i = 0; i < ol.size(); i++) {
	
		Object *o = ol.at(i);
		SDL_Rect r = o->getRect();
		Id id = ol.at(i)->getId();

		switch (id) {
			case BACKGROUND:
				SDL_RenderCopy(renderer, o->getTexture(), NULL, NULL);
				break;
			case PLAYER:
			case BOMB:
			case FRIEND:
				SDL_RenderCopy(renderer, o->getTexture(), NULL, &r);
				break;
			case ENEMY:
				SDL_RenderCopyEx(renderer, o->getTexture(), NULL, &r, ENEMYANGLE, NULL, SDL_FLIP_NONE);
				break;
			default:
				cerr << "How did you even manage to get this error output?\n";
				break;
		}
	}

	SDL_RenderPresent(renderer);
}

SDL_Renderer* Graphics::getRenderer(void) const
{
	return renderer;
}

SDL_Window* Graphics::getWindow(void) const
{
	return window;
}

