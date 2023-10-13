#include <./include/Character.h>

// Implementation of Character Methods

void Character::flip() { std::cout << "CHARACTER : I know how to flip and I will flipping do it" << std::endl; }
void Character::walk() { std::cout << "CHARACTER : Just in case they are too young to walk yet" << std::endl; }

void Character::chooseWeapon() //player chooses their desired weapon
{
	int weapon;
	std::cout<<"    Bat - 1\n    Sword - 2\n    Axe - 3\n";
	std::cin>>weapon;
	if(weapon==1) //bat
	{
		m_weapon= &m_bat; //current weapon is bat
        std::cout<<"\nYou have a BAT\n";
	}
	else if(weapon==2) //sword
	{
        if(m_sword.canUse()) 
        {
		    m_weapon=&m_sword; //current weapon is a sword
            std::cout<<"\nYou have a SWORD\n";

        }
        else 
        {
            std::cout<<"***The sword cooldown is 2 rounds. Current amount of unused rounds: "<<m_sword.getUnusedRounds()<<"***\n!!!Choose again!!!\n";
            choose();
        }
	}
    else if(weapon==3) //axe
	{
        if(m_axe.canUse()) 
        {
		    m_weapon=&m_axe; //current weapon is an axe
            std::cout<<"\nYou have an AXE\n";

        }
        else 
        {
            std::cout<<"***The axe cooldown is 7 rounds. Current amount of unused rounds: "<<m_axe.getUnusedRounds()<<"***\n!!!Choose again!!!\n";
            choose();
        }
	}
    else
    {
        std::cout<<"!!!You have to choose from these: \n";
        chooseWeapon();
    }
}

void Character::chooseBarrier() //player chooses their desired defence barrier
{
    int barrier;
	std::cout<<"    Shield - 1\n    Armour - 2\n";
	std::cin>>barrier;
	if(barrier==1)
	{
        if(m_shield.canUse())
        {
		    m_weapon=&m_shield; //player currently has a shield
            std::cout<<"\nYou have a SHIELD\n";
        }
        else
        {
            std::cout<<"***The shield cooldown is 1 round. Current amount of unused rounds: "<<m_shield.getUnusedRounds()<<"***\n!!!Choose again!!!\n";
            choose();
        }
	}
    else if(barrier==2)
    {
        if(m_armour.canUse())
        {
		    m_weapon=&m_armour; //player currently has an armour
            std::cout<<"\nYou have an ARMOUR \n";
        }
        else
        {
            std::cout<<"***The armour cooldown is 7 rounds. Current amount of unused rounds: "<<m_armour.getUnusedRounds()<<"***\n!!!Choose again!!!\n";
            choose();
        }
    }
    else
    {
        std::cout<<"!!!You have to choose from these: \n";
        chooseBarrier();
    }
	
}

void Character::choose() //player chooses if they want to attack or defend
{
    int ans;
	std::cout<<"Attack or defend?\n";
	std::cout<<"    Attack - 1\n    Defend - 2\n";
	std::cin>>ans;
    
	if(ans==1) //attack
	{
		chooseWeapon();
	}
	else if(ans ==2) //defend 
	{
        chooseBarrier();
	}
    else
    {
        std::cout<<"!!!Invalid input!!!\n";
        choose();
    }
}

void Character::autoChoose() //chooses current weapon automatically 
{   
    Attack weapon=static_cast<Attack>(rand()%5); //chooses weapons or defences
    if(weapon==Attack::BAT)
    {
        m_weapon=&m_bat;
        std::cout<<"Enemy has a BAT\n";
    }
    else if(weapon==Attack::SWORD && m_sword.canUse())
    {
        m_weapon=&m_sword;
        std::cout<<"Enemy has a SWORD\n";
    }
    else if( weapon==Attack::SHIELD && m_shield.canUse())
    {
        m_weapon= &m_shield;
        std::cout<<"Enemy has a SHIELD\n";

    }
    else if( weapon==Attack::ARMOUR && m_armour.canUse())
    {
        m_weapon= &m_armour;
        std::cout<<"Enemy has an ARMOUR\n";

    }
    else if( weapon==Attack::AXE && m_axe.canUse())
    {
        m_weapon= &m_axe;
        std::cout<<"Enemy has an AXE\n";

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



void Character::adjustHealth(int t_value) //changes health after a round
{
    if(m_health+t_value<100)
    {
        m_health=m_health+t_value;
    }
    else if(m_health<100) //100 is max limit
    {
        m_health=100;
    }

    if(m_health<=0) //0 is min limit
    {
        m_health=0;
        m_alive=false; //character is dead
    }
    else
    {
        m_alive=true; //possibility to set it back to alive when playing again
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

void Character::increaseRoundWeapons() //increases number of unused rounds for weapons
{
    m_bat.increaseUnusedRounds();
    m_sword.increaseUnusedRounds();
    m_shield.increaseUnusedRounds();
    m_armour.increaseUnusedRounds();
    m_axe.increaseUnusedRounds();
}