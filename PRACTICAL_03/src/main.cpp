#include <iostream>

#include <./include/Orc.h>
#include <./include/Troll.h>

using namespace std;



Type  selectCharacter() //user chooses either orc or troll
	{
		string ans="";
		Type player=Type::NONE;
		while (player==Type::NONE)
		{
			cout<<"\n--------------------\nSelect your character\n	Troll - T\n	Orc - O\n";
			cin>>ans;
			if(ans=="t"|| ans=="T") //player chose troll
			{
				player=Type::TROLL;
			}
			else if(ans=="o" || ans=="O") //player chose orc
			{
				player= Type::ORC;
			}
			else //error check
			{
				cout<<"\nYou have to choose Troll or Orc!\n";
			}
		}
		return player; 
	}

	Type selectEnemy() //autochooses character type for enemy
	{
		Type enemy=static_cast<Type>((rand()%2)+1); //troll or orc
		
		return enemy;
	}

	
	void calculateHealth(Character* player, Character* enemy) //calculates players and enemies health according to the game economy and displays them
	{
		if(player->getWeapon()->getWeaponType()==Attack::BAT)
		{
			if(enemy->getWeapon()->getWeaponType()==Attack::BAT) //bat vs bat
			{
				player->adjustHealth(-20);
				enemy->adjustHealth(-20);
			}
			else if(enemy->getWeapon()->getWeaponType()==Attack::SWORD) //bat vs sword
			{
				player->adjustHealth(-30);
			}
			else if(enemy->getWeapon()->getWeaponType()==Attack::SHIELD) //bat vs shield
			{
				player->adjustHealth(10);
			}
		}
		else if(player->getWeapon()->getWeaponType()==Attack::SWORD)
		{
			if(enemy->getWeapon()->getWeaponType()==Attack::BAT) //sword vs bat
			{
				player->adjustHealth(20);
			}
			else if(enemy->getWeapon()->getWeaponType()==Attack::SWORD) //sword vs sword
			{
				player->adjustHealth(-10);
				enemy->adjustHealth(-10);
			}
			else if(enemy->getWeapon()->getWeaponType()==Attack::SHIELD) //sword vs shield
			{
				player->adjustHealth(30);
			}
		}
		else if(player->getWeapon()->getWeaponType()==Attack::SHIELD)
		{
			if(enemy->getWeapon()->getWeaponType()==Attack::BAT) //shield vs bat
			{
				player->adjustHealth(10);
			}
			else if(enemy->getWeapon()->getWeaponType()==Attack::SWORD) //shield vs sword
			{
				player->adjustHealth(-30);
			}
			else if(enemy->getWeapon()->getWeaponType()==Attack::SHIELD) //shield vs shield
			{
				player->adjustHealth(-10);
				enemy->adjustHealth(-10);
			}
		}
		
		cout<<"\n~~~~~~~~~~~~~~~~~~~~\n";
		cout<<"Player health: "<<player->getHealth()<<"\n";
		cout<<"Enemy health: "<<enemy->getHealth()<<"\n";
		cout<<"~~~~~~~~~~~~~~~~~~~~\n";

	}

	

	

	void play(Troll&trollP, Orc&orcP, Troll&trollE, Orc&orcE)
	{
		Character* player=nullptr;
		Character* enemy=nullptr;

		Type playerType=selectCharacter(); //returns type of selected character by player
		if(playerType==Type::TROLL)
		{
			player=&trollP; //player plays as a troll
			cout<<"\nCongrats, you have chosen TROLL\n";

		}
		else if(playerType==Type::ORC)
		{
			player=&orcP; //player plays as an orc
			cout<<"\nCongrats, you have chosen ORC\n";

		}
		
		Type enemyType=selectEnemy(); //returns type of autoselected character
		if(enemyType==Type::TROLL)
		{
			enemy=&trollE; //enemy is troll
			cout<<"Your enemy is TROLL\n";

		}
		else if(enemyType==Type::ORC)
		{
			enemy=&orcE; //enemy is orc
			cout<<"Your enemy is ORC\n";

		}
		cout<<"--------------------\n";

		int roundCounter=1; //counts the rounds
		while(player->getAlive() && enemy->getAlive()) 
		{
			cout<<"\n///////\nROUND "<<roundCounter<<"\n///////\n";
			player->choose();
			enemy->autoChoose();
			player->increaseRoundWeapons();
			enemy->increaseRoundWeapons();
			player->getWeapon()->setUnusedRounds(0); //"this weapon has been used"
			enemy->getWeapon()->setUnusedRounds(0); //"this weapon has been used"
			calculateHealth(player, enemy); 
			roundCounter++;
		}

		int ans;
		if(player->getHealth()==enemy->getHealth()) //draw
		{
			cout<<"Draw :|\nDo you want to play again?\n	Yes - 1\n	No - 2\n";
			cin>>ans;
		}
		else if(player->getHealth()==0) //winner
		{
			cout<<"You have lost :(\nDo you want to play again?\n	Yes - 1\n	No - 2\n";
			cin>>ans;
		}
		else if(enemy->getHealth()==0) //loser
		{
			cout<<"You have won :)\nDo you want to play again?\n	Yes- 1\n	No - 2\n";
			cin>>ans;
		}

		if(ans==1) //play again
		{
			player->adjustHealth(100); //alive again
			enemy->adjustHealth(100);
			play(trollP, orcP, trollE, orcE);
		}
	}


int main() {
	//cout << "Let go virtual" << endl;

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

	//player objects
	Troll trollP;
	Orc orcP;

	//enemy objects
	Troll trollE;
	Orc orcE;

	//main game loop
	play(trollP, orcP, trollE, orcE);

	cin.get();

}