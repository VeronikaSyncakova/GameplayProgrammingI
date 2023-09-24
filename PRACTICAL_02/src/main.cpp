#include <iostream>

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

	void selectWarhead()
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
		else{
			cout<<"Please select again !\n";
			selectWarhead();
		}
	}

	void acquireTarget()
	{
		int x,y,ans;
		cout<<"\nSelect target position (0-6)\n";
		cout<<"x: ";
		cin>>x;
		cout<<"y: ";
		cin>>y;
		cout<<"You have chosen\n["<<x<<" ,"<<y<<" ]\n*Change the target-0\n*Fire-1\n";
		cin>>ans;
		if(ans==0)
		{
			acquireTarget();
		}
		else
		{
			coordinates.x=x;
			coordinates.y=y;
		}
	}

	bool fire()
	{
		int chance=rand()%11; //chance that the weather will be suitable for attack
		bool fire=false;
		if(payload==EXPLOSIVE)
		{
			if(chance>5)
			{
				fire=true;
			}
		}
		else{
			if(chance>3)
			{
				fire=true;
			}
		}
		return fire;
	}

	bool checkCollision()
	{
		if( target.coordinates.x==coordinates.x && target.coordinates.y==coordinates.y)
		{
			return true;
		}
		else{
			return false;
		}
	}
};



int main()
{
	// Create a new Enemy
	Enemy *e = new Enemy();

	// Set Enemy Position / Target
	e->coordinates.x = 2;
	e->coordinates.y = 2;
	
	while( e->alive)
	{
		// Print Enemy Position
		cout<<"//////////////////////////////////\n";
		cout << "Print Enemy Position" << endl;
		e->coordinates.print();
		cout<<"//////////////////////////////////\n";

		// Create a new Missile
		Missile *m = new Missile();

		//Select warhead
		m->selectWarhead();

		// Set Missile Target by dereferencing Enemy pointer
		m->target = *e;
		//Acquire target
		m->acquireTarget();

		//Fire
		while(!(m->fire()))
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
			cout<<"Try again!\n\n";
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