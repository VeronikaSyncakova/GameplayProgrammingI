#include <./include/Rectangle.h>

Rectangle::Rectangle(){}

Rectangle::~Rectangle(){}

void Rectangle::initialize(int t_x,int t_y,int t_w,int t_h, sf::Color color)
{
    x=t_x;
	y=t_y;
	r=0;
    w=t_w;
    h=t_h;
    body.setSize(sf::Vector2f(w,h));
	body.setFillColor(color);
	body.setPosition(sf::Vector2f(x,y));

    
}

void Rectangle::moveUp()
{
	if(y>0)
	{
		y-=3;
	}
	body.setPosition(sf::Vector2f(x,y));
}

void Rectangle::moveDown()
{
	if(y+h<600)
	{
		y+=3;
	}
	body.setPosition(sf::Vector2f(x,y));
}
void Rectangle::moveRight()
{
	if(x+w<800)
	{
		x+=3;
	}
	body.setPosition(sf::Vector2f(x,y));
}
void Rectangle::moveLeft()
{
	if(x>0)
	{
		x-=3;
	}
	body.setPosition(sf::Vector2f(x,y));
}