#include "game.h"
#include "background.h"
#include "player.h"
#include "bomb.h"
#include "enemy.h"
#include "friend.h"

Game::Game()
{
	playerIndex = -1;
	objectList.clear();
	graphics = new Graphics;
}

Game::~Game()
{
	delete graphics;
	graphics = NULL;

	for (size_t i = 0; i < objectList.size(); i++) {
		delete objectList.at(i);
	}
}

int Game::init(void)
{
	if (graphics->init() != 0) {
		std::cerr << "Unable to init SDL\n";
		return EXIT_FAILURE;
	}

	SDL_Renderer *rend = graphics->getRenderer();
#ifndef LEVEL4
	objectList.push_back(new Background(rend));
	objectList.push_back(new Player(rend));
#endif
#if LEVEL1
	objectList.push_back(new Enemy(rend, ENEMYIMG, {ENEMYSTARTX, ENEMYSTARTY, ENEMYWIDTH, ENEMYHEIGHT}));
#elif LEVEL2
	objectList.push_back(new Enemy(rend, ENEMYIMG, { 0, ENEMYSTARTY, WIDTH, ENEMYHEIGHT}));
#elif LEVEL3
	objectList.push_back(new Enemy(rend, ENEMYIMG, { 0, ENEMYSTARTY, WIDTH, ENEMYHEIGHT}));
#elif LEVEL4
	objectList.push_back(new Background(rend));
	objectList.push_back(new Friend(rend, ENEMYIMG, {int(WIDTH*0.8), HEIGHT/2, ENEMYWIDTH/2, ENEMYWIDTH/2}));
#endif

#ifndef LEVEL4	
	for (size_t i = 0; i < objectList.size(); i++) {
		Id id = objectList.at(i)->getId();
		if (id == PLAYER) {
			playerIndex = i;
			break;
		}
	}

	if (playerIndex == -1) {
		cerr << "No player initialized\n";
		return EXIT_FAILURE;
	}
#endif

	return 0;
}


void Game::run(void)
{
#ifndef LEVEL4
	bool d = true;
#endif
	bool quit = false;
	SDL_Event e;

	while (quit != true) {
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				quit = true;
#ifndef LEVEL4
			else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE && d) {
				dropBomb(playerIndex);
				d = !d;
			} else if (e.type == SDL_KEYUP)
				d = !d;
#endif
		}
		
		graphics->renderObjects(objectList);
#ifndef LEVEL4
		handleMovingObjects();
#endif	
	}


}

void Game::handleMovingObjects(void)
{
	Id id;
	for (size_t i = 0; i < objectList.size(); i++) {
		id = objectList.at(i)->getId();
		if (id == PLAYER || id == BOMB)
			if (objectList.at(i)->move() == CHANGEIMAGE) 
				objectList.at(i)->changeImage(graphics->getRenderer(), LANDEDBOMB);
	}
}

void Game::dropBomb(int pi)
{
	SDL_Rect r = objectList.at(pi)->getRect();
	r.y = r.y + PLAYERHEIGHT;
	r.w = BOMBWIDTH;
	r.h = BOMBHEIGHT;
	
	SDL_Renderer *rend = graphics->getRenderer();
	objectList.push_back(new Bomb(rend, r));		
}
