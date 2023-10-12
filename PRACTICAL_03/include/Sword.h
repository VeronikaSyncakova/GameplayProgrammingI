#ifndef SWORD_H
#define SWORD_H

#include <./include/Weapon.h>

class Sword:public Weapon
{
public:
    Attack getWeaponType();

private:
    int m_COOLDOWN=2;
    int m_unusedRounds=0;
    
};

#endif