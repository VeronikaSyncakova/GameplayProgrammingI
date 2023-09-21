#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

class Character {
public:
	void flip();
	virtual void walk();
	virtual void fly() = 0;
};
#endif