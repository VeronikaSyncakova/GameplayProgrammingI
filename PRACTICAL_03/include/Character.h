#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

enum class Type {NONE,TROLL, ORC};
enum class Attack {NONE,BAT,SWORD};
enum class Defend {NONE,Shield};

// Abstract Character Class

class Character {
public:
	void flip();
	virtual void walk(); 	// Virtual Method Implemented by Character or Subclass(es)
	virtual void fly() = 0; // Pure virtual function which makes Character Class an Abstract Class
	virtual Type getType()=0; //returns the type of a character
	virtual void choose(int t_roundCounter); // enables player to choose weapon or shield
	virtual void chooseWeapon(); //player can choose which weapon they want to use
	bool getAlive();
	

private:
	bool m_alive=true;
	int m_health=100;
	Attack m_weapon=Attack::NONE;
	Defend m_barrier=Defend::NONE;
};
#endif