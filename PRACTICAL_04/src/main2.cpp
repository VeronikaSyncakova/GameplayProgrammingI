//#include <./include/Game.h>
#include <./include/Circle.h>
#include <./include/Rectangle.h>

int main(void){
/*
	Game* game = new Game();
	game->run();
*/
Circle p(39,50,10);
Circle enemy(40,50,10);
p.circle2circle(enemy);

Rectangle pl(10,10,10,10);
Rectangle en(20,20,10,10);
pl.rectangle2rectangle(en);

Rectangle en2(15,15,10,10);
pl.rectangle2rectangle(en2);
}