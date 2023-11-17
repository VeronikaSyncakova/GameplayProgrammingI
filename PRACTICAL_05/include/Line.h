#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <./include/GameObject.h>


using namespace std;

class Line
{
public:
    Line();
    void setStart(sf::Vector2f t_a);
    void setEnd(sf::Vector2f t_b);
    void initialize(sf::Vector2f t_a,sf::Vector2f t_b);
    void draw(sf::RenderWindow* window);

    sf::VertexArray line { sf::Lines };
    sf::Vector2f a;
    sf::Vector2f b;
    
    
};

#endif