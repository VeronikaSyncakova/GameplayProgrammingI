#include <./include/Bat.h>

Bat::Bat():Weapon(0,0)
{
    
}

Attack Bat::getWeaponType()
{
    return Attack::BAT;
}

bool Bat::canUse()
{
    return true;
}