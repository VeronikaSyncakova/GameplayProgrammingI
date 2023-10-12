#ifndef SHIELD_H
#define SHIELD_H

#include <./include/Weapon.h>

class Shield:public Weapon
{
public:
    Attack getWeaponType();
    
};

#endif