#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <./include/GameObject.h>


using namespace std;

class Circle : public GameObject
{
public:
	Circle();
	~Circle();
	void initialize(int t_radius, sf::Color color);
	void update();
	void draw();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void setPosition();

	sf::CircleShape body;

};
#endif