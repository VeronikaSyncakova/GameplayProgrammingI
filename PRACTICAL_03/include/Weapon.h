#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

enum class Attack {BAT,SWORD, SHIELD, ARMOUR, AXE};
class Weapon //abstract weapon class
{
public:
    Weapon(int t_coolDown=0, int t_unusedRounds=0);
    virtual Attack getWeaponType()=0; //returns weapon type
    virtual bool canUse(); //if the weapon can or can not be used
    void increaseUnusedRounds(); 
    void setUnusedRounds(int t_value);
    int getUnusedRounds();

private:
    int m_coolDown;
    int m_unusedRounds;


};


#endif 