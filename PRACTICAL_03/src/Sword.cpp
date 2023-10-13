#include <./include/Sword.h>

Sword::Sword():Weapon(2,2) //cooldown=2 unused rounds=2
{

}

Attack Sword::getWeaponType()
{
    return Attack::SWORD;
}

