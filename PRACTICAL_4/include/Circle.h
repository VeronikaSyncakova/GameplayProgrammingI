#ifndef CIRCLE_H
#define CIRCLE_H

class Circle 
{
public:
    Circle(float t_x=0, float t_y=0, float t_radius=5);
    bool circle2circle(Circle t_enemy);

private:
    float m_x;
    float m_y;
    float m_radius;

};


#endif