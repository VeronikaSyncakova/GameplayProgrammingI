#include <iostream>

#include <./include/Orc.h>
#include <./include/Troll.h>

using namespace std;

int main() {
	cout << "Let go virtual" << endl;

	// Uncomment and try to compile. Why are errors produced?
	//Character character;
	//character.flip();
	//character.walk();

	cout << "Let go create an Orc" << endl;
	Orc orc;		// Creates a Orc reference
	orc.walk();		// Method call walk
	orc.fly();		// Method call fly
	orc.flip();		// Method call flip

	cout << "Let go create an Troll" << endl;
	Troll troll;	// Creates a Troll reference
	troll.walk();	// Method call walk
	troll.fly();	// Method call fly
	troll.flip();	// Method call flip

	// Assign Orc memory address to npc pointer
	Character* npc = &orc;
	npc->flip(); 	// Bound at compile time -> action based on type
	npc->fly();  	// Bound at runtime -> action based on pointer
	npc->walk(); 	// Bound at runtime -> action based on pointer

	// Assign Troll memory address to npc pointer
	npc = &troll; 
	npc->flip(); 	// Bound at compile time -> action based on type
	npc->fly();  	// Bound at runtime -> action based on pointer
	npc->walk();	// Bound at runtime -> action based on pointer

	cin.get();

}