#include <./include/Armour.h>

Armour::Armour():Weapon(7,7) //cooldown=7, unused rounds=7
{
    
}

Attack Armour::getWeaponType()
{
    return Attack::ARMOUR;
}

