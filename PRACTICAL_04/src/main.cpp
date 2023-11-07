#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
#include <./include/Circle.h>
#include <./include/Rectangle.h>
#include <math.h>
#include <SFML/Graphics.hpp>

using namespace std;

//m_displacementX=target.x-coordinates.x;
//m_displacementY=target.y-coordinates.y;
//m_displacementX /= sqrtf(m_displacementX*m_displacementX + m_displacementY*m_displacementY);
//m_displacementY /= sqrtf(m_displacementX*m_displacementX + m_displacementY*m_displacementY);
//m_displacementX*=1 (speed)
//m_displacementY*=1 (speed)




typedef struct Position
{
	float x=0;
	float y=0;
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
	Target coordinates;
	Coordinates position;
	Circle colliderC;
	Rectangle colliderR;
	Target target;
	
	//launch code
	string const LAUNCH_CODE="fire";

	bool armed;

	void setColliderPosition() //sets position of colliders
	{
		colliderC.setPosition(position.x,position.y);
		colliderR.setPosition(position.x,position.y);
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
		const float SPEED=1;
		float displacementX=coordinates.coordinates.x-position.x;
		float displacementY=coordinates.coordinates.y-position.y;
		//std::cout<<"displacementX before sqrt: "<<displacementX<<"\n";
		displacementX /= sqrtf(displacementX*displacementX + displacementY*displacementY);
		displacementY /= sqrtf(displacementX*displacementX + displacementY*displacementY);
		//std::cout<<"displacementX after sqrt: "<<displacementX<<"\n";
		displacementX*=SPEED; //(speed)
		displacementY*=SPEED; //(speed)
		//std::cout<<"position X before displacement: "<<position.x<<"\n";
		position.x += displacementX;
		position.y += displacementY;
		//std::cout<<"position X after displacement: "<<position.x<<"\n";
		setColliderPosition();
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
			coordinates.coordinates.x=x;
			coordinates.coordinates.y=y;
			coordinates.setColliderPosition();
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
			if( target.coordinates.x==coordinates.coordinates.x && target.coordinates.y==coordinates.coordinates.y)
			{
				collision= true;
			}
		}
		else //hit area is 1 pixel to each side 
		{
			int radiusX[]={coordinates.coordinates.x-1,coordinates.coordinates.x, coordinates.coordinates.x+1}; //hit areas for x
			int radiusY[]={coordinates.coordinates.y-1,coordinates.coordinates.y, coordinates.coordinates.y+1}; //hit areas for y
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

	bool checkCollisionColliders() //checks for collision betweencolliders
	{
		bool collision=false;
		if(payload==EXPLOSIVE)
		{
			if(colliderC.circle2circle(target.colliderC))
			{
				cout<<"circle collision\n";
				collision=true;
			}
			else if(colliderC.circle2circle(coordinates.colliderC))
			{
				//std::cout<<"target.colliderC X: "<<target.colliderC.getX()<<"\n";
				//std::cout<<"coordinates.colliderC X: "<<coordinates.colliderC.getX()<<"\n";
				cout<<"arrived at target\n";
				collision=true;
			}
		}
		else if(payload==NUCLEAR)
		{
			if(colliderR.rectangle2rectangle(target.colliderR))
			{
				cout<<"rectangle collision\n";
				collision=true;
			}
			else if(colliderR.rectangle2rectangle(coordinates.colliderR))
			{
				cout<<"arrived at target\n";
				collision=true;
			}
		}

		return collision;
	}

	bool viable() //checks if the coordinates are within the playing area
	{
		if (coordinates.coordinates.x<0 || coordinates.coordinates.x>6 || coordinates.coordinates.y<0 || coordinates.coordinates.y>6) //coordinates outside of the area
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

void openWindow(Missile* m, Enemy* e)
	{
		sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "Launching...");
		window->setSize(sf::Vector2u(640, 480));
		window->setTitle("Game");

		while(window->isOpen())
		{
			/*sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
		}*/
			while (!m->checkCollisionColliders())
			{
				m->update();
			}
			window->close();
		}
	}

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
		m->target.setColliderPosition();
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

		openWindow(m,e);
		/*
		while (!m->checkCollisionColliders(e))
		{
			m->update();
		}*/

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
				m->position.x=0;
				m->position.y=0;
				m->setColliderPosition();
			}
		}
	}
		
	cin.get();
}