#ifndef STRUCTS_H
#define STRUCTS_H

#define WIDTH 800
#define HEIGHT 600
#ifndef LEVEL4
#define GAMENAME "Eat shit new Lı.u logo"
#else
#define GAMENAME "All hail the old logo, our ONLY HERO!!!"
#endif
#define MAGIC_MSG "68747470733a2f2f7676762e786f75747562652e636f6d2f76617463683f753d6451763476395767586351"


#ifdef LEVEL1
#define ENEMYANGLE -8
#define BACKGROUNDIMG "imgs/background.jpg"
#define ENEMYIMG "imgs/enemy.jpg"
#define PLAYERIMG "imgs/player.png"
#define FALLINGBOMB "imgs/bomb.png"
#define LANDEDBOMB "imgs/landedbomb.png"
#elif LEVEL2
#define ENEMYANGLE 0
#define BACKGROUNDIMG "imgs/background2.jpg"
#define ENEMYIMG "imgs/enemy2.png"
#define PLAYERIMG "imgs/puking.png"
#define FALLINGBOMB "imgs/bomb2.png"
#define LANDEDBOMB "imgs/landedbomb2.png"
#elif LEVEL3
#define ENEMYANGLE 0
#define BACKGROUNDIMG "imgs/sky.jpg"
#define ENEMYIMG "imgs/enemy3.png"
#define PLAYERIMG "imgs/player3.png"
#define FALLINGBOMB "imgs/bomb3.png"
#define LANDEDBOMB "imgs/landedbomb3.png"
#define PLAYERSTARTX WIDTH/2
#define PLAYERSTARTY (WIDTH % HEIGHT)/8
#define PLAYERWIDTH WIDTH/3
#define PLAYERHEIGHT HEIGHT/3
#elif LEVEL4
#define BACKGROUNDIMG "imgs/friend.png"
#define ENEMYIMG "imgs/salut.png"
#define PLAYERIMG "imgs/player2.png"
#define FALLINGBOMB "imgs/bomb2.png"
#define LANDEDBOMB "imgs/landedbomb2.png"
#define ENEMYANGLE 0
#endif

#define FRIENDIMG "imgs/friend.png"

#ifndef LEVEL3
#define PLAYERSTARTX WIDTH/2
#define PLAYERSTARTY (WIDTH % HEIGHT)/8
#define PLAYERWIDTH WIDTH/4
#define PLAYERHEIGHT HEIGHT/4
#endif


#define ENEMYWIDTH WIDTH/3
#define ENEMYHEIGHT HEIGHT/4
#define ENEMYSTARTX WIDTH/3
#define ENEMYSTARTY HEIGHT-ENEMYHEIGHT

#define BOMBWIDTH PLAYERWIDTH/6
#define BOMBHEIGHT PLAYERHEIGHT/6
#define LANDEDBOMBWIDTH BOMBWIDTH*1.5
#define LANDEDBOMBHEIGHT BOMBHEIGHT*1.5

enum Speed {
	SLOW = 3,
	MEDIUM = 2,
	XTC = 1
};

enum Direction {
	LEFT,
	RIGHT
};

enum Id {
	BACKGROUND,
	ENEMY,
	FRIEND,
	PLAYER,
	BOMB
};

enum Bombstate {
	FALLING,
	LANDED
};

enum Returncodes {
	CHANGEIMAGE = 2
};

#endif // STRUCTS_H
