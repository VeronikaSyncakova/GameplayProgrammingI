#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>


using namespace std;

typedef struct Position
{
	int x;
	int y;
	void
	print()
	{
		cout << "[ x: " << x << " ]" << "[ y: " << y << " ]" << endl;
	}
} Coordinates;

enum WarHead
{
	EXPLOSIVE,
	NUCLEAR
};

typedef struct Enemy
{
	Coordinates coordinates;
	bool alive=true;
} Target;

struct Missile
{
	WarHead payload;
	Coordinates coordinates;
	Target target;
	//launch code
	string const LAUNCH_CODE="816 80085";

	bool armed;

	void arm()
	{
		if (armed)
			armed = false;
		else
			armed = true;
	}

	void update()
	{
		coordinates.x += 1;
		coordinates.y += 2;
	}

	void selectWarhead() //select warhead type
	{
		int warhead;
		cout<<"Select warhead\n*Explosive-0\n*Nuclear-1\n";
		cin>>warhead;
		if(warhead==EXPLOSIVE){
			payload = WarHead::EXPLOSIVE;
			cout<<"You have chosen: explosive\n";

		}
		else if(warhead==NUCLEAR){
			payload = WarHead::NUCLEAR;
			cout<<"You have chosen: nuclear\n";
		}
		else{ //error check for invalid input
			cout<<"Please select again !\n";
			selectWarhead();
		}
	}

	void acquireTarget() //set the shooting target
	{
		int x,y,ans;
		cout<<"\nSelect target position (0-6)\n"; //6x6
		cout<<"x: ";
		cin>>x;
		cout<<"y: ";
		cin>>y;
		cout<<"You have chosen\n["<<x<<" ,"<<y<<" ]\n*Change the target-0\n*Fire-1\n"; //options 
		cin>>ans;
		if(ans==0) //user wants to change the target
		{
			acquireTarget();
		}
		else //user fires 
		{
			coordinates.x=x;
			coordinates.y=y;
		}
	}

	void  launchCode()
	{ /*
		string ans="";
			cout<<"Enter launch code: ";
			cin>>static_cast<string>(ans);
			while(!(ans==LAUNCH_CODE))
			{
				cout<<"\nEnter launch code or press 0 to view the launch code: ";
				cin>>static_cast<string>(ans);

				if (ans=="1")
				{
					cout<<"\nLaunch code: "<<LAUNCH_CODE<<"\n";
				}
			}
			*/
	}

	bool fire() //checks if it was possible to fire or if the user had bad luck
	{
		int chance=rand()%11; //chance that the weather will be suitable for attack
		bool fire=false;
		if(payload==EXPLOSIVE)
		{
			if(chance>5) //lower chance
			{
				fire=true;
			}
		}
		else{
			if(chance>3) //higher chance 
			{
				fire=true;
			}
		}
		return fire;
	}

	bool checkCollision() //check collision between missiole and target
	{
		if( target.coordinates.x==coordinates.x && target.coordinates.y==coordinates.y)
		{
			return true;
		}
		else{
			return false;
		}
	}
	bool viable() //checks if the coordinates are within the playing area
	{
		if (coordinates.x<0 || coordinates.x>6 || coordinates.y<0 || coordinates.y>6) //coordinates outside of the area
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


int main()
{
	// Create a new Enemy
	Enemy *e = new Enemy();

	// Set Enemy Position / Target
	srand(time(nullptr));
	e->coordinates.x = rand()%7;
	e->coordinates.y = rand()%7;

	// Print Enemy Position
	cout<<"//////////////////////////////////\n";
	cout << "Print Enemy Position" << endl;
	e->coordinates.print();
	cout<<"//////////////////////////////////\n";

	// Create a new Missile
	Missile *m = new Missile();

	//launch code
	cout<<"Launch code: "<<m->LAUNCH_CODE<<"\n";
	
	
	while( e->alive) //keep playing while the enemy is not destroyed
	{

		//Select warhead
		m->selectWarhead();

		// Set Missile Target by dereferencing Enemy pointer
		m->target = *e;
		//Acquire target
		m->acquireTarget();

		//Fire
		while(!(m->fire())) //if the weather is bad, repeat until you can shoot
		{
			int ans;
			cout<<"Bad weather, couldn't attack.\n*Press 1 to fire again\n";
			cin>>ans;
			if (ans==1)
			{
				m->fire();
			}
		}

		//check collision and destroy the target
		if(m->checkCollision())
		{
			cout<<"Hit! Target destroyed!\n";
			e->alive=false;
		}
		else{
			if (m->viable())
			{
				cout<<"Target outside of the board!\nThe board is 6x6\n\n";
				//m->acquireTarget();
			}
			else{
				cout<<"Missed, try again!\n\n";
			}
		}
	}

	/*
	// Set Initial Position
	m->coordinates.x = 0;
	m->coordinates.y = 0;

	// Print Position
	cout << "Print Missile Position" << endl;
	m->coordinates.print();

	// Update Position
	m->update();

	// Print Missile Position
	cout << "Print Missile Position after an Update" << endl;
	m->coordinates.print();


	// Print Missile target
	cout << "Print Missile Target Position" << endl;
	m->target.coordinates.print();*/

	cin.get();
}