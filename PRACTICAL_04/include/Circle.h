#ifndef CIRCLE_H
#define CIRCLE_H

class Circle 
{
public:
    Circle(float t_x=0, float t_y=0, float t_radius=0.5);
    bool circle2circle(Circle t_enemy);
    void setPosition(float t_x,float t_y);
    float getX();
    float getY();

private:
    float m_x;
    float m_y;
    float m_radius;

};


#endif