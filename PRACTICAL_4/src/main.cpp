#include <./include/Game.h>

int main(void){
/*
	Game* game = new Game();
	game->run();
*/
Circle p(39,50,10);
Circle enemy(40,50,10);
p.circle2circle(enemy);
}