#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

enum class Type {NONE,TROLL, ORC};

// Abstract Character Class

class Character {
public:
	void flip();
	virtual void walk(); 	// Virtual Method Implemented by Character or Subclass(es)
	virtual void fly() = 0; // Pure virtual function which makes Character Class an Abstract Class
	virtual Type getType()=0; //returns the type of a character
};
#endif