#ifndef GAME_H
#define GAME_H

#include "object.h"
#include "graphics.h"


class Game {
 public:

	Game();
	~Game();
	
	int init(void);
	void run(void);

	void handleMovingObjects(void);
	void dropBomb(int);

	Graphics* getGraphics(void) const;


 private:
	Graphics *graphics;
	int playerIndex;
	vector<Object*> objectList; // make a typedef for this? HELL nah..I give less fucks than the new liu logo designer stfu 
};

#endif
