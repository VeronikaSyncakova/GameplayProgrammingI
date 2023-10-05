#ifndef ORC_H
#define ORC_H

#include <./include/Character.h>

// Orc is a Character
class Orc : public Character{

public:
	void barrelRoll(); 	// Method only available in Orc
	void walk(); 		// Specific implementation of walk()
	void fly(); 		// implementation of pure virtual
};

#endif