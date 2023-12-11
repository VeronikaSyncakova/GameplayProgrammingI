#include <Circle.h>

Circle::Circle()
{
}

void Circle::setCircle(int radius, sf::Vector2f position)
{
    m_radius=radius;
    m_position=position;
    m_collisionCircle.p=c2V(m_position.x, m_position.y);
    m_collisionCircle.r=m_radius;
    m_body.setPosition(m_position);
    m_body.setRadius(m_radius);
    m_body.setOutlineColor(sf::Color::Green);
    //m_body.setFillColor(sf::Color::Green);
}

bool Circle::circleCollision(c2Circle t_circle)
{
    if(c2CircletoCircle(m_collisionCircle, t_circle))
	{
        return true;
	} 
	else
	{
        return false;
	}
}

void Circle::moveCircle(int direction)
{
    m_position.x+=direction;
    m_body.setPosition(m_position);
    m_collisionCircle.p=c2V(m_position.x, m_position.y);
}

c2Circle Circle::getCollisionCircle()
{
    return m_collisionCircle;
}

sf::CircleShape Circle::getBody()
{
    return m_body;
}

void Circle::setPosition(sf::Vector2f t_position)
{
    m_position=t_position;
    m_body.setPosition(m_position);
    m_collisionCircle.p=c2V(m_position.x, m_position.y);
}
