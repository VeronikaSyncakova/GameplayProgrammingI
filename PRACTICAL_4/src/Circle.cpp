#include <./include/Circle.h>
#include <iostream>
#include <math.h>

Circle::Circle(float t_x, float t_y, float t_radius): m_x(t_x),m_y(t_y),m_radius(t_radius)
{
}

bool Circle::circle2circle(Circle t_enemy)
{
    float radius= m_radius+t_enemy.m_radius;
    float x= (m_x-t_enemy.m_x) * (m_x-t_enemy.m_x);
    float y= (m_y-t_enemy.m_y) * (m_y-t_enemy.m_y);
    float distance= sqrtf(x+y);
    std::cout<<x<<"\n";
    std::cout<<distance<<"\n";

    if (distance<=radius)
    {
        std::cout<<"collision\n";
        return true;
    }
    return false;
}