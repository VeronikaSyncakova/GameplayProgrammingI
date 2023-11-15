#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <./include/GameObject.h>

using namespace std;

class Rectangle : public GameObject
{
public:
	Rectangle();
	~Rectangle();
	void initialize(int t_x,int t_y,int t_w,int t_h, sf::Color color);
	void update();
	void draw();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	sf::RectangleShape body;
};
#endif