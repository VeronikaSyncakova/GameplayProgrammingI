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