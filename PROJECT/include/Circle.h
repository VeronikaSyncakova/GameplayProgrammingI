#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>
#include <cute_c2.h>



class Circle 
{
    public:
        Circle();
        void setCircle(int radius, sf::Vector2f position);
        bool circleCollision(c2Circle t_circle);
        void moveCircle(int direction);
        c2Circle getCollisionCircle();
        sf::CircleShape getBody();
        void setPosition(sf::Vector2f t_position);

    private:
       sf::CircleShape m_body;
       int m_radius;
       c2Circle m_collisionCircle;
       sf::Vector2f m_position;

};
#endif