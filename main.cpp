#include <iostream>
#include "game.h"

int main(void)
{
	Game game;


	if (game.init() != 0) {
		std::cerr << "Unable to init game\n";
		return EXIT_FAILURE;	
	}	

	game.run();

	return 0;
}
