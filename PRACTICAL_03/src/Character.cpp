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
}

void Character::choose(int t_roundCounter)
{
    int ans;
    std::cout<<"ROUND "<<t_roundCounter<<"\n";
	std::cout<<" Attack or defend?\n";
	std::cout<<"Attack - 1\nDefend - 2\n";
	std::cin>>ans;
	if(ans==1)
	{
		chooseWeapon();
	}
	else if(ans ==2)
	{
        std::cout<<"defend\n";
	}
}


bool Character::getAlive() 
{
    return m_alive;
}