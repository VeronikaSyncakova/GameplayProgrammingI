#include <./include/Shield.h>

Shield::Shield():Weapon(1,1) //cooldown = 1 unused rounds=1
{

}

Attack Shield::getWeaponType()
{
    return Attack::SHIELD;
}

