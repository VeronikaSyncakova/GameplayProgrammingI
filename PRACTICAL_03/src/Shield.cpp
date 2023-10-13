#include <./include/Shield.h>

Shield::Shield():Weapon(1,1)
{
    
}

Attack Shield::getWeaponType()
{
    return Attack::SHIELD;
}

