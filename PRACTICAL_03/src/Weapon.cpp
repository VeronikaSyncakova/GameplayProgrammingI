#include <./include/Weapon.h>

bool Weapon::canUse()
{
    if(m_unusedRounds<m_COOLDOWN)
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