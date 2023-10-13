#include <./include/Weapon.h>

Weapon::Weapon(int t_coolDown, int t_unusedRounds): m_coolDown(t_coolDown), m_unusedRounds(t_unusedRounds)
{

}

bool Weapon::canUse()
{
    if(m_unusedRounds>=m_coolDown)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Weapon::increaseUnusedRounds()
{
    m_unusedRounds++;
}

void Weapon::setUnusedRounds(int t_value)
{
    m_unusedRounds=t_value;
}

int Weapon::getUnusedRounds()
{
    return m_unusedRounds;
}