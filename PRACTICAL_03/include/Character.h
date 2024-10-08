#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <ctime>
#include <cstdlib>

#include <./include/Weapon.h>
#include <./include/Bat.h>
#include <./include/Sword.h>
#include <./include/Shield.h>
#include <./include/Armour.h>
#include <./include/Axe.h>


enum class Type {NONE,TROLL, ORC};


// Abstract Character Class

class Character {
public:
	void flip();
	virtual void walkIntoFight(); 	// Virtual Method Implemented by Character or Subclass(es)
	virtual void winMessage() = 0; // Pure virtual function which makes Character Class an Abstract Class

	virtual Type getType()=0; //returns the type of a character
	virtual void choose(); // enables player to choose weapon or shield
	virtual void chooseWeapon(); //player can choose which weapon they want to use
	virtual void chooseBarrier(); //player chooses a barrier
	virtual void autoChoose(); //enemy randomised weapon or barrier
	bool getAlive();
	void adjustHealth(int t_value);
	Weapon* getWeapon(); //returns pointer to the players weapon
	int getHealth();
	void increaseRoundWeapons(); //increases unused rounds for weapons

	

private:
	bool m_alive=true;
	int m_health=100;
	Weapon* m_weapon=nullptr;
	Bat m_bat;
	Sword m_sword;
	Shield m_shield;
	Armour m_armour;
	Axe m_axe;
};
#endif