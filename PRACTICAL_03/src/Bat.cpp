#include <./include/Bat.h>

Attack Bat::getWeaponType()
{
    return Attack::BAT;
}

bool Bat::canUse()
{
    return true;
}