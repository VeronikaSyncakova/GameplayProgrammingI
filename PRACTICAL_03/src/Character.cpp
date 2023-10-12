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
		m_weapon= new Bat;
	}
	else if(weapon==2)
	{
		m_weapon=new Sword;
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
		m_weapon=new Shield;
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
    //m_weapon=Attack::NONE;
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
    Attack weapon=static_cast<Attack>(rand()%2); //chooses weapons or shield
    if(weapon==Attack::BAT)
    {
        m_weapon=new Bat;
        std::cout<<"Enemy has a bat\n";
    }
    else if(weapon==Attack::SWORD)
    {
        m_weapon=new Sword;
        std::cout<<"Enemy has a sword\n";
    }
    else if( weapon==Attack::SHIELD)
    {
        m_weapon= new Shield;
        std::cout<<"Enemy has a shield\n";

    }
}


bool Character::getAlive() 
{
    return m_alive;
}



void Character::adjustHealth(int t_value)
{
    m_health=m_health+t_value;
}

Weapon* Character::getWeapon()
{
    return m_weapon;
}

int Character::getHealth()
{
    return m_health;
}

