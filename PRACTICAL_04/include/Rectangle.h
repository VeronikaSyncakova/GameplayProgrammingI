#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle 
{
public:
    Rectangle(float t_x=0, float t_y=0, float t_width=5, float t_height=5);
    bool rectangle2rectangle(Rectangle t_enemy);
    void setPosition(float t_x,float t_y);


private:
    float m_x;
    float m_y;
    float m_width;
    float m_height;

};


#endif