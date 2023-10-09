#include <iostream>

#include <./include/Orc.h>
#include <./include/Troll.h>

using namespace std;



Type  selectCharacter()
	{
		string ans="";
		Type player=Type::NONE;
		while (player==Type::NONE)
		{
			cout<<"\n//////////\nSelect your character\nTroll - T\nOrc - O\n";
			cin>>ans;
			if(ans=="t"|| ans=="T")
			{
				//cout<<"\nTroll\n";
				player=Type::TROLL;
			}
			else if(ans=="o" || ans=="O")
			{
				//cout<<"\nOrc\n";
				player= Type::ORC;
			}
			else
			{
				cout<<"\nYou have to choose Troll or Orc!\n";
			}
		}
		return player;
	}

	Type selectEnemy()
	{
		Type enemy=static_cast<Type>((rand()%2)+1);
		/*Type enemy=Type::NONE;
		if(num==Type::TROLL)
		{
			enemy=Type::TROLL;
		}
		else if(num==Type::ORC)
		{
			enemy=Type::ORC;
		}*/
		return enemy;
	}

	

	void play(Troll&trollP, Orc&orcP, Troll&trollE, Orc&orcE)
	{
		Character* player=nullptr;
		Character* enemy=nullptr;
		Type playerType=selectCharacter();
		if(playerType==Type::TROLL)
		{
			player=&trollP;
			cout<<"Congrats, you have chosen troll\n";

		}
		else if(playerType==Type::ORC)
		{
			player=&orcP;
			cout<<"Congrats, you have chosen orc\n";

		}
		
		player->getType();

		Type enemyType=selectEnemy();
		if(enemyType==Type::TROLL)
		{
			enemy=&trollE;
			cout<<"Your enemy is troll\n";

		}
		else if(enemyType==Type::ORC)
		{
			enemy=&orcE;
			cout<<"Your enemy is orc\n";

		}
		enemy->getType();

		int roundCounter=1;
		while(player->getAlive() && enemy->getAlive())
		{
			player->choose(roundCounter);
			enemy->autoChoose();
			//calculateHealth();
			roundCounter++;
		}
	}


int main() {
	cout << "Let go virtual" << endl;

	// Uncomment and try to compile. Why are errors produced?
	//Character character;
	//character.flip();
	//character.walk();
	//Character is an abstract class, therefore no instances can be made

	/*

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

	*/
	
	srand(time(nullptr));

	//player
	Troll trollP;
	Orc orcP;

	//enemy
	Troll trollE;
	Orc orcE;

	play(trollP, orcP, trollE, orcE);

	cin.get();

}