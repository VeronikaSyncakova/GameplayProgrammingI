#ifndef GAME_H
#define GAME_H

#include <./include/Player.h>
#include <./include/NPC.h>
#include <./include/Circle.h>


enum class GameState{BOUNDING,C2CIRCLE,C2CAPSULE,C2AABB,C2RAY};

class Game
{
	public:
		Game();
		void run();
	private:
		void initialize();
		void update();
		void draw();
		void c2circleCollision();
		void c2capsuleCollision();
		Player* player;
		NPC* npc;
		Circle* circleP;
		Circle* circleE;
		GameState currentGameState;
};

#endif