#ifndef SHIELD_H
#define SHIELD_H

#include <./include/Weapon.h>

class Shield:public Weapon
{
public:
    Attack getWeaponType();
private:
    int const m_COOLDOWN=1;
    int m_unusedRounds=0;
};

#endif