#ifndef WEAPON_H
#define WEAPON_H

enum class Attack {BAT,SWORD, SHIELD};
class Weapon
{
public:
    virtual Attack getWeapon()=0; //returns weapon type

private:
    

};


#endif 