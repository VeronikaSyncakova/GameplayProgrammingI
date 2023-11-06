#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
#include <./include/Circle.h>
#include <./include/Rectangle.h>

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
	Circle colliderC;
	Rectangle colliderR;
	bool alive=true;

	void setColliderPosition()
	{
		colliderC.setPosition(coordinates.x,coordinates.y);
		colliderR.setPosition(coordinates.x,coordinates.y);
	}
} Target;

struct Missile
{
	WarHead payload;
	Coordinates coordinates;
	Circle colliderC;
	Rectangle colliderR;
	Target target;
	
	//launch code
	string const LAUNCH_CODE="fire";

	bool armed;

	void setColliderPosition()
	{
		colliderC.setPosition(coordinates.x,coordinates.y);
		colliderR.setPosition(coordinates.x,coordinates.y);
	}

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
		cout<<"Select warhead [nuclear has higher chance of bad weather conditions]\n*Explosive-0   [1x1]\n*Nuclear-1     [+1 vertically and horizontally]\n";
		cin>>warhead;
		if(warhead==EXPLOSIVE){
			payload = WarHead::EXPLOSIVE;
			cout<<"You have chosen: explosive\n_____________________________________________\n";

		}
		else if(warhead==NUCLEAR){
			payload = WarHead::NUCLEAR;
			cout<<"You have chosen: nuclear\n_____________________________________________\n";
		}
		else{ //error check for invalid input
			cout<<"Please select again !\n";
			selectWarhead();
		}
	}

	void acquireTarget() //set the shooting target
	{
		int x,y,ans;
		cout<<"\nSelect target position (0-6) [Aquire target]\n"; //6x6
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
			
			launchCode();
		}
	}

	void  launchCode() //launch code is fire
	{ 
		string ans="";
			cout<<"Enter launch code: ";
			cin>>ans;
			while(!(ans==LAUNCH_CODE))
			{
				cout<<"\nEnter launch code or press 0 to view the launch code: ";
				cin>>ans;

				if (ans=="0") //shows launch code again
				{
					cout<<"\nLaunch code: "<<LAUNCH_CODE<<"\n";
				}
			}
		cout<<"\n^Arm missile^\n\n";
	}

	bool fire() //checks if it was possible to fire or if the user had bad luck
	{
		int chance=rand()%11; //chance that the weather will be suitable for attack
		bool fire=false;
		if(payload==EXPLOSIVE)
		{
			if(chance>3) //lower chance
			{
				fire=true;
			}
		}
		else{
			if(chance>6) //higher chance 
			{
				fire=true;
			}
		}
		return fire;
	}

	bool checkCollision() //check collision between missiole and target
	{
		bool collision=false; //if collision is succesfull
		if (payload==EXPLOSIVE) //hit area is 1x1
		{
			if( target.coordinates.x==coordinates.x && target.coordinates.y==coordinates.y)
			{
				collision= true;
			}
		}
		else //hit area is 1 pixel to each side 
		{
			int radiusX[]={coordinates.x-1,coordinates.x, coordinates.x+1}; //hit areas for x
			int radiusY[]={coordinates.y-1,coordinates.y, coordinates.y+1}; //hit areas for y
			bool collisionX=false; //collision on x
			bool collisionY=false; //collision on y
			for (int i=0; i<3;i++)
			{
				if( target.coordinates.x==radiusX[i] ) //collision on x
				{
					collisionX= true;
				}
				if(target.coordinates.y==radiusY[i]) //collision on y
				{
					collisionY=true;
				}
				if(collisionX && collisionY) // general collision 
				{
					collision=true;
				}
			}
		}
		return collision;

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
	e->setColliderPosition();


	// Print Enemy Position
	cout<<"\n//////////////////////////////////\n";
	cout << "Print Enemy Position" << endl;
	e->coordinates.print();
	cout<<"//////////////////////////////////\n";

	// Create a new Missile
	Missile *m = new Missile();

	//launch code
	cout<<"\n_____________________________________________\n";
	cout<<"Launch code: "<<m->LAUNCH_CODE<<"\n";
	cout<<"_____________________________________________\n\n\n";
		
		
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
			cout<<"!!!!Bad weather, couldn't attack.\n*Press 1 to fire again!!!!\n";
			cin>>ans;
			if (ans==1)
			{
				m->fire();
			}
		}

		//check collision and destroy the target
		if(m->checkCollision())
		{
			cout<<":: Hit! Target destroyed! ::\n";
			e->alive=false;
				
		}
		else{
			if (m->viable()) //checks if the missile is within the board range
			{
				cout<<"|| Target outside of the board!\nThe board is 6x6 ||\n\n";
					
			}
			else{
				cout<<":: Missed, try again! ::\n\n";
			}
		}
	}
		
	cin.get();
}