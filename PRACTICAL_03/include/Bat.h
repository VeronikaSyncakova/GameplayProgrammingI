#ifndef BAT_H
#define BAT_H

#include <./include/Weapon.h>

class Bat:public Weapon
{
public:
    Bat();
    Attack getWeaponType();
    bool canUse();
private:
    
};

#endif