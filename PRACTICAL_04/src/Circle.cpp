#include <./include/Circle.h>
#include <iostream>
#include <math.h>

Circle::Circle(float t_x, float t_y, float t_radius): m_x(t_x),m_y(t_y),m_radius(t_radius)
{
}

bool Circle::circle2circle(Circle t_enemy)
{
    float radius= m_radius+t_enemy.m_radius;
    float x= (m_x-t_enemy.getX()) * (m_x-t_enemy.getX());
    float y= (m_y-t_enemy.getY()) * (m_y-t_enemy.getY());
    float distance= sqrtf(x+y);
    //std::cout<<x<<"\n";
    //std::cout<<distance<<"\n";

    if (distance<radius)
    {
        std::cout<<"collision\n";
        return true;
    }
    return false;
}

void Circle::setPosition(float t_x, float t_y)
{
    m_x=t_x;
    m_y=t_y;
    std::cout<<"position x: "<<m_x<<"\n";
    std::cout<<"position y: "<<m_y<<"\n";
}

float Circle::getX()
{
    return m_x;
}

float Circle::getY()
{
    return m_y;
}