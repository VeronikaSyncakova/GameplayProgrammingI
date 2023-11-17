#ifndef GAME_H
#define GAME_H

#include <./include/Player.h>
#include <./include/NPC.h>
#include <./include/Circle.h>
#include <./include/Rectangle.h>


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
		void c2AABBcollision();
		void c2rayCollision();
		void capsuleMoveUp();
		void capsuleMoveDown();
		void capsuleMoveRight();
		void capsuleMoveLeft();
		void drawCapsule();
		
		Player* player;
		NPC* npc;
		Circle* circleP;
		Circle* circleE;
		Circle* circleCapsule;
		Circle* circleCapsuleR;
		Rectangle* rectangleCapsule;
		Rectangle* line;
		GameState currentGameState;
};

#endif