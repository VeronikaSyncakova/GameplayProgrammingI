#ifndef ARMOUR_H
#define ARMOUR_H

#include <./include/Weapon.h>

class Armour:public Weapon
{
public:
    Armour();
    Attack getWeaponType();
private:
    
};

#endif