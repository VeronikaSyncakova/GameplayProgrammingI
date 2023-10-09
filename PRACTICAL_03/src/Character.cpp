#include <./include/Character.h>

// Implementation of Character Methods

void Character::flip() { std::cout << "CHARACTER : I know how to flip and I will flipping do it" << std::endl; }
void Character::walk() { std::cout << "CHARACTER : Just in case they are too young to walk yet" << std::endl; }

void Character::chooseWeapon()
{
	int weapon;
	std::cout<<"Bat - 1\nSword - 2\n";
	std::cin>>weapon;
	if(static_cast<Attack>(weapon)==Attack::BAT)
	{
		m_weapon=Attack::BAT;
	}
	else if(static_cast<Attack>(weapon)==Attack::SWORD)
	{
		m_weapon=Attack::SWORD;
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
	if(static_cast<Defend>(barrier)==Defend::SHIELD)
	{
		m_barrier=Defend::SHIELD;
	}
    else
    {
        std::cout<<"You have to choose from these: \n";
        chooseBarrier();
    }
	
}

void Character::choose(int t_roundCounter)
{
    int ans;
    m_weapon=Attack::NONE;
    m_barrier=Defend::NONE;
    std::cout<<"\n/////\nROUND "<<t_roundCounter<<"\n";
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
    m_weapon=Attack::NONE;
    m_barrier=Defend::NONE;    
    int num=rand()%2;
    if (num==0) //attack
    {
        m_weapon=static_cast<Attack>((rand()%2)+1); //bat or sword
        if(m_weapon==Attack::BAT)
        {
            std::cout<<"Enemy has a bat\n";
        }
        else if(m_weapon==Attack::SWORD)
        {
            std::cout<<"Enemy has a sword\n";
        }
    }
    else if(num==1)
    {
        m_barrier=Defend::SHIELD;
        std::cout<<"Enemy has a shield\n";

    }
}


bool Character::getAlive() 
{
    return m_alive;
}