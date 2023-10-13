#ifndef SHIELD_H
#define SHIELD_H

#include <./include/Weapon.h>

class Shield:public Weapon
{
public:
    Shield();
    Attack getWeaponType();
private:
    
};

#endif