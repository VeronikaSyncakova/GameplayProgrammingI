#ifndef BAT_H
#define BAT_H

#include <./include/Weapon.h>

class Bat:public Weapon
{
public:
    Attack getWeaponType();
    bool canUse();
private:
    int m_COOLDOWN=0;
    int m_unusedRounds=1;
};

#endif