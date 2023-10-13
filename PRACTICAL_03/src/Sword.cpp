#include <./include/Sword.h>

Sword::Sword():Weapon(2,2)
{
    
}

Attack Sword::getWeaponType()
{
    return Attack::SWORD;
}

