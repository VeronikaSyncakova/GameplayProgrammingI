#include <./include/Circle.h>

Circle::Circle(){}

Circle::~Circle(){}

void Circle::initialize(int t_radius, sf::Color color)
{
    x=0;
	y=0;
	r=t_radius;
    w=100;
    h=100;
    body.setRadius(t_radius);
	body.setFillColor(color);
	body.setPosition(sf::Vector2f(x,y));

    
}

void Circle::moveUp()
{
	if(y>0)
	{
		y-=3;
	}
	body.setPosition(sf::Vector2f(x,y));
}

void Circle::moveDown()
{
	if(y+h<600)
	{
		y+=3;
	}
	body.setPosition(sf::Vector2f(x,y));
}
void Circle::moveRight()
{
	if(x+w<800)
	{
		x+=3;
	}
	body.setPosition(sf::Vector2f(x,y));
}
void Circle::moveLeft()
{
	if(x>0)
	{
		x-=3;
	}
	body.setPosition(sf::Vector2f(x,y));
}

void Circle::setPosition()
{
	body.setPosition(sf::Vector2f(x,y));
}