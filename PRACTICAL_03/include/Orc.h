#ifndef ORC_H
#define ORC_H

#include <./include/Character.h>

// Orc is a Character
class Orc : public Character{

public:
	void barrelRoll(); 	// Method only available in Orc
	void walkIntoFight(); 		// Specific implementation of walk()
	void winMessage(); 		// implementation of pure virtual
	Type getType(); 
};

#endif