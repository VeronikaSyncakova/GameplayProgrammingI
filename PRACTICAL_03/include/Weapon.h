#ifndef WEAPON_H
#define WEAPON_H

enum class Attack {BAT,SWORD, SHIELD};
class Weapon
{
public:
    virtual Attack getWeaponType()=0; //returns weapon type
    virtual bool canUse(); //if the weapon can or can not be used
    void increaseUnusedRounds(); 
    void setUnusedRounds(int t_value);
    int getUnusedRounds();

private:
    int const m_COOLDOWN=0;
    int m_unusedRounds=1;


};


#endif 