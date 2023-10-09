#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <ctime>
#include <cstdlib>

enum class Type {NONE,TROLL, ORC};
enum class Attack {NONE,BAT,SWORD};
enum class Defend {NONE,SHIELD};

// Abstract Character Class

class Character {
public:
	void flip();
	virtual void walk(); 	// Virtual Method Implemented by Character or Subclass(es)
	virtual void fly() = 0; // Pure virtual function which makes Character Class an Abstract Class
	virtual Type getType()=0; //returns the type of a character
	virtual void choose(int t_roundCounter); // enables player to choose weapon or shield
	virtual void chooseWeapon(); //player can choose which weapon they want to use
	virtual void chooseBarrier(); //player chooses a barrier
	virtual void autoChoose(); //enemy randomised weapon or barrier
	bool getAlive();
	

private:
	bool m_alive=true;
	int m_health=100;
	Attack m_weapon=Attack::NONE;
	Defend m_barrier=Defend::NONE;
};
#endif