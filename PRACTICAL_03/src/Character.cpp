#include <./include/Character.h>

// Implementation of Character Methods

void Character::flip() { std::cout << "CHARACTER : I know how to flip and I will flipping do it" << std::endl; }
void Character::walk() { std::cout << "CHARACTER : Just in case they are too young to walk yet" << std::endl; }

void Character::chooseWeapon()
{
	int weapon;
	std::cout<<"Bat - 1\nSword - 2\n";
	std::cin>>weapon;
	if(weapon==1)
	{
		m_weapon= &m_bat;
	}
	else if(weapon==2)
	{
        
        if(m_sword.canUse())
        {
		    m_weapon=&m_sword;
        }
        else
        {
            std::cout<<"The sword cooldown is 2 rounds. Current amount of unused rounds: "<<m_sword.getUnusedRounds()<<"\nChoose again\n";
            choose();
        }
	}
    else
    {
        std::cout<<"You have to choose from these: \n";
        chooseWeapon();
    }
}

void Character::chooseBarrier()
{
    int barrier;
	std::cout<<"Shield - 1\n";
	std::cin>>barrier;
	if(barrier==1)
	{
        if(m_shield.canUse())
        {
		    m_weapon=&m_shield;
        }
        else
        {
            std::cout<<"The shield cooldown is 1 round. Current amount of unused rounds: "<<m_shield.getUnusedRounds()<<"\nChoose again\n";
            choose();
        }
	}
    else
    {
        std::cout<<"You have to choose from these: \n";
        chooseBarrier();
    }
	
}

void Character::choose()
{
    int ans;
	std::cout<<"Attack or defend?\n";
	std::cout<<"Attack - 1\nDefend - 2\n";
	std::cin>>ans;
    
	if(ans==1)
	{
		chooseWeapon();
	}
	else if(ans ==2)
	{
        chooseBarrier();
	}
}

void Character::autoChoose()
{   
    Attack weapon=static_cast<Attack>(rand()%3); //chooses weapons or shield
    if(weapon==Attack::BAT)
    {
        m_weapon=&m_bat;
        std::cout<<"Enemy has a bat\n";
    }
    else if(weapon==Attack::SWORD && m_sword.canUse())
    {
        m_weapon=&m_sword;
        std::cout<<"Enemy has a sword\n";
    }
    else if( weapon==Attack::SHIELD && m_sword.canUse())
    {
        m_weapon= &m_shield;
        std::cout<<"Enemy has a shield\n";

    }
    else
    {
        autoChoose();
    }
}


bool Character::getAlive() 
{
    return m_alive;
}



void Character::adjustHealth(int t_value)
{
    if(m_health+t_value<100)
    {
        m_health=m_health+t_value;
    }
    else if(m_health<100)
    {
        m_health=100;
    }

    if(m_health<=0)
    {
        m_health=0;
        m_alive=false;
    }
}

Weapon* Character::getWeapon()
{
    return m_weapon;
}

int Character::getHealth()
{
    return m_health;
}

void Character::increaseRoundWeapons()
{
    m_bat.increaseUnusedRounds();
    m_sword.increaseUnusedRounds();
    m_shield.increaseUnusedRounds();
}