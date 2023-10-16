#ifndef TROLL_H
#define TROLL_H

#include <./include/Character.h>

// Troll is a Character

class Troll : public Character{
public:
	void winMessage();			// implementation of pure virtual
	void walkIntoFight();
	Type getType();
	void motivation(); //only avaliable in troll
};

#endif

