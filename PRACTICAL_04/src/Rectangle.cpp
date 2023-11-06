#include <./include/Rectangle.h>
#include <iostream>
#include <math.h>

Rectangle::Rectangle(float t_x, float t_y, float t_width, float t_height): m_x(t_x),m_y(t_y),m_width(t_width), m_height(t_height)
{
}

bool Rectangle::rectangle2rectangle(Rectangle t_enemy)
{
    if(m_x+m_width>=t_enemy.m_x &&
    m_x<=t_enemy.m_x+t_enemy.m_width &&
    m_y+m_height>=t_enemy.m_y &&
    m_y<=t_enemy.m_y+t_enemy.m_height)
    {
        std::cout<<"collision rect\n";
        return true;
    }
    else
    {
        return false;
    }

}

void Rectangle::setPosition(float t_x, float t_y)
{
    m_x=t_x;
    m_y=t_y;
}