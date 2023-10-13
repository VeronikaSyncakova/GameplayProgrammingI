#include <./include/Axe.h>

Axe::Axe():Weapon(7,7) //cooldown=7, unused rounds=7
{
    
}

Attack Axe::getWeaponType()
{
    return Attack::AXE;
}