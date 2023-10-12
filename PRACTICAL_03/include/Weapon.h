#ifndef WEAPON_H
#define WEAPON_H

enum class Attack {BAT,SWORD, SHIELD};
class Weapon
{
public:
    virtual Attack getWeaponType()=0; //returns weapon type
    virtual bool canUse(); //if the weapon can or can not be used
private:
    int const m_COOLDOWN=0;
    int m_unusedRounds=0;

};


#endif 