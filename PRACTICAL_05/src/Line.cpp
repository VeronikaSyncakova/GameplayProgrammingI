#include <./include/Line.h>

Line::Line()
{}

void Line::setStart(sf::Vector2f t_a)
    {
        a=t_a;
    }

void Line::setEnd(sf::Vector2f t_b)
{
    b=t_b;
}

void Line::initialize(sf::Vector2f t_a,sf::Vector2f t_b)
{
    a=t_a;
    b=t_b;
    line.append(a);
    line.append(b);
}

void Line::draw(sf::RenderWindow* window)
{
    window->draw(line);
    
}