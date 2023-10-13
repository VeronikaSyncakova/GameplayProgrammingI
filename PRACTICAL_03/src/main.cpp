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
		
		return enemy;
	}

	
	void calculateHealth(Character* player, Character* enemy)
	{
		if(player->getWeapon()->getWeaponType()==Attack::BAT)
		{
			if(enemy->getWeapon()->getWeaponType()==Attack::BAT)
			{
				player->adjustHealth(-20);
				enemy->adjustHealth(-20);
			}
			else if(enemy->getWeapon()->getWeaponType()==Attack::SWORD)
			{
				player->adjustHealth(-30);
			}
			else if(enemy->getWeapon()->getWeaponType()==Attack::SHIELD)
			{
				player->adjustHealth(10);
			}
		}
		else if(player->getWeapon()->getWeaponType()==Attack::SWORD)
		{
			if(enemy->getWeapon()->getWeaponType()==Attack::BAT)
			{
				player->adjustHealth(20);
			}
			else if(enemy->getWeapon()->getWeaponType()==Attack::SWORD)
			{
				player->adjustHealth(-10);
				enemy->adjustHealth(-10);
			}
			else if(enemy->getWeapon()->getWeaponType()==Attack::SHIELD)
			{
				player->adjustHealth(30);
			}
		}
		else if(player->getWeapon()->getWeaponType()==Attack::SHIELD)
		{
			if(enemy->getWeapon()->getWeaponType()==Attack::BAT)
			{
				player->adjustHealth(10);
			}
			else if(enemy->getWeapon()->getWeaponType()==Attack::SWORD)
			{
				player->adjustHealth(-30);
			}
			else if(enemy->getWeapon()->getWeaponType()==Attack::SHIELD)
			{
				player->adjustHealth(-10);
				enemy->adjustHealth(-10);
			}
		}
		cout<<"Player health: "<<player->getHealth()<<"\n";
		cout<<"Enemy health: "<<enemy->getHealth()<<"\n";


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
		
		//player->getType();

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
		//enemy->getType();

		int roundCounter=1;
		while(player->getAlive() && enemy->getAlive())
		{
			cout<<"\n/////\nROUND "<<roundCounter<<"\n";
			player->choose();
			enemy->autoChoose();
			player->increaseRoundWeapons();
			enemy->increaseRoundWeapons();
			player->getWeapon()->setUnusedRounds(0);
			enemy->getWeapon()->setUnusedRounds(0);
			calculateHealth(player, enemy);
			roundCounter++;
		}

		int ans;
		if(player->getHealth()==enemy->getHealth())
		{
			cout<<"Draw :|\nDo you want to play again?\n Yes - 1\nNo - 2\n";
			cin>>ans;
		}
		else if(player->getHealth()==0)
		{
			cout<<"You have lost :(\nDo you want to play again?\nYes - 1\nNo - 2\n";
			cin>>ans;
		}
		else if(enemy->getHealth()==0)
		{
			cout<<"You have won :)\nDo you want to play again?\nYes- 1\nNo - 2\n";
			cin>>ans;
		}

		if(ans==1)
		{
			player->adjustHealth(100); //alive again
			enemy->adjustHealth(100);
			play(trollP, orcP, trollE, orcE);
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