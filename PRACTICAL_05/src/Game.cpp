#include <./include/Game.h>
#include <SFML/Graphics.hpp>

using namespace sf;

#define CUTE_C2_IMPLEMENTATION
#include <./include/cute_c2.h>

sf::RenderWindow* window = new RenderWindow(sf::VideoMode(800, 600), "Launching...");


sf::Texture player_texture;
sf::Texture npc_texture;

sf::Sprite player_sprite;
sf::Sprite npc_sprite;
bool moveCapsule=false;
bool displayCapsule=false;



Game::Game(){}

void Game::initialize()
{
	player = new Player();
	npc = new NPC();
	circleP= new Circle();
	circleE= new Circle();
	line= new Rectangle();
	circleCapsule=new Circle();
	rectangleCapsule= new Rectangle();
	circleCapsuleR=new Circle();
	rayLine=new Line();
	currentGameState=GameState::BOUNDING;
	window->setSize(sf::Vector2u(640, 480));
	window->setTitle("Game");

	/*player->x = 0;
	player->y = 0;
	player->w = 0;
	player->h = 0;
	player->r = 0;

	npc->x = 0;
	npc->y = 0;
	npc->w = 0;
	npc->h = 0;
	npc->r = 0;*/

	player->initialize();
	npc->initialize();
	circleP->initialize(50,sf::Color::Red);
	circleE->initialize(50,sf::Color::Yellow);
	line->initialize(200,300,250,5,sf::Color::White);
	circleCapsule->initialize(50,sf::Color::Yellow);
	circleCapsuleR->initialize(50,sf::Color::Yellow);
	rectangleCapsule->initialize(200,250,250,100,sf::Color::Yellow);
	rayLine->initialize(sf::Vector2f(0,0),sf::Vector2f(400,300));
	
	std::cout<<"Q\nW\nE\nR\nT (pressC to see capsule)\n";
	/*player_texture.loadFromFile(".//images//player//Player.png");
	npc_texture.loadFromFile(".//images//npc//npc.png");

	player_sprite.setTexture(player_texture);
	npc_sprite.setTexture(npc_texture);*/
}

void Game::run()
{
	initialize();

	while (window->isOpen())
	{
		update();
		draw();
	}
}

void Game::update()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();

		player->update();
		npc->update();

		switch(currentGameState)
		{
			case GameState::BOUNDING:
				//Setup NPC AABB
				c2AABB aabb_npc;
				aabb_npc.min = c2V(npc->m_sprite.getPosition().x, npc->m_sprite.getPosition().y); //lft top
				aabb_npc.max = c2V(
					npc->m_sprite.getPosition().x +
					npc->m_sprite.getGlobalBounds().width, 
					npc->m_sprite.getPosition().y +
					npc->m_sprite.getGlobalBounds().height); //right bottom
					
				//Setup Player AABB
				c2AABB aabb_player;
				aabb_player.min = c2V(player->m_sprite.getPosition().x,player->m_sprite.getPosition().y); //left top
				aabb_player.max = c2V(player->m_sprite.getGlobalBounds().width, player->m_sprite.getGlobalBounds().height); //right bottom
				
				if(c2AABBtoAABB(aabb_npc, aabb_player)){
					cout << "NPC and Player are in Collision" << endl;
					player->m_sprite.setColor(sf::Color::Blue);
					player->m_boundingBox.setOutlineColor(sf::Color::Blue);
				} else{
					cout << "No Collision" << endl;
					player->m_sprite.setColor(sf::Color::White);
					player->m_boundingBox.setOutlineColor(sf::Color::Green);
				}
				break;
			case GameState::C2CIRCLE:
				//circle to circle setup and collision check
				c2circleCollision();
				break;
			case GameState::C2CAPSULE:
				//c2 capsule setup and collision check
				c2capsuleCollision();
				break;
			case GameState::C2AABB:
				c2AABBcollision();
				break;
			case GameState::C2RAY:
				c2rayCollision();
				break;
		}


		// Move the player
		if(event.type== sf::Event::KeyPressed)
		{
			if (sf::Keyboard::Up == event.key.code)
			{
				player->moveUp();
				circleP->moveUp();
				if(moveCapsule)
				{
					capsuleMoveUp();
				}
			}
			else if (sf::Keyboard::Down == event.key.code)
			{
				player->moveDown();
				circleP->moveDown();
				if(moveCapsule)
				{
					capsuleMoveDown();
				}
			}
			else if (sf::Keyboard::Right == event.key.code)
			{
				player->moveRight();
				circleP->moveRight();
				if(moveCapsule)
				{
					capsuleMoveRight();
				}
			}
			else if (sf::Keyboard::Left == event.key.code)
			{
				player->moveLeft();
				circleP->moveLeft();
				if(moveCapsule)
				{
					capsuleMoveLeft();
				}
			}
		}
		if(event.type==sf::Event::KeyReleased)
		{
			if(sf::Keyboard::Q==event.key.code)
			{
				currentGameState=GameState::BOUNDING;
				moveCapsule=false;
			}
			else if(sf::Keyboard::W==event.key.code)
			{
				currentGameState=GameState::C2CIRCLE;
				circleP->x=0;
				circleP->y=0;
				circleE->x=400;
				circleE->y=300;
				moveCapsule=false;
			}
			else if(sf::Keyboard::E==event.key.code)
			{
				currentGameState=GameState::C2CAPSULE;
				circleP->x=0;
				circleP->y=0;
				circleE->x=-400;
				circleE->y=-300;
				moveCapsule=false;
				rectangleCapsule->initialize(200,250,250,100,sf::Color::Yellow);
				rectangleCapsule->setPosition();
				line->initialize(200,300,250,5,sf::Color::White);
				line->setPosition();
				
			}
			else if(sf::Keyboard::R==event.key.code)
			{
				currentGameState=GameState::C2AABB;
				npc->x=400;
				npc->y=300;
				npc->m_sprite.setPosition(sf::Vector2f(npc->x,npc->y));
				npc->m_boundingBox.setPosition(sf::Vector2f(npc->x,npc->y));
				circleP->x=0;
				circleP->y=0;
				circleE->x=-400;
				circleE->y=-300;
				moveCapsule=true;

			}
			else if(sf::Keyboard::T==event.key.code)
			{
				currentGameState=GameState::C2RAY;
				moveCapsule=true;
				displayCapsule=false;
			}
			else if(sf::Keyboard::C==event.key.code && currentGameState==GameState::C2RAY)
			{
				displayCapsule=true;
			}

			circleE->setPosition();
			circleP->setPosition();
		}
	}

}

void Game::capsuleMoveUp()
{
	if(circleCapsule->y>0)
	{
		circleCapsule->y-=3;
		circleCapsuleR->y-=3;
		rectangleCapsule->y-=3;
		line->y-=3;
	}
	rectangleCapsule->setPosition();
	line->setPosition();
}

void Game::capsuleMoveDown()
{
	if(circleCapsule->y+circleCapsule->h<600)
	{
		circleCapsule->y+=3;
		circleCapsuleR->y+=3;
		rectangleCapsule->y+=3;
		line->y+=3;
	}
	rectangleCapsule->setPosition();
	line->setPosition();
}

void Game::capsuleMoveLeft()
{
	if(circleCapsuleR->x>0)
	{
		circleCapsule->x-=3;
		circleCapsuleR->x-=3;
		rectangleCapsule->x-=3;
		line->x-=3;
	}
	rectangleCapsule->setPosition();
	line->setPosition();
}

void Game::capsuleMoveRight()
{
	if(circleCapsule->x+circleCapsule->w<800)
	{
		circleCapsule->x+=3;
		circleCapsuleR->x+=3;
		rectangleCapsule->x+=3;
		line->x+=3;
	}
	rectangleCapsule->setPosition();
	line->setPosition();
}

void Game::c2circleCollision() //c2circle to circle collision
{
	c2Circle circle_circleP;
	circle_circleP.p=c2V(circleP->x,circleP->y);
	circle_circleP.r=circleP->r;

	c2Circle circle_circleE;
	circle_circleE.p=c2V(circleE->x,circleE->y);
	circle_circleE.r=circleE->r;
	circleE->body.setFillColor(sf::Color::Yellow);
	circleE->body.setOutlineColor(sf::Color::Transparent);

	if(c2CircletoCircle(circle_circleP, circle_circleE))
	{
		cout << "Circles are in Collision" << endl;
		circleP->body.setFillColor(sf::Color::Blue);
	} 
	else
	{
		cout << "No Collision" << endl;
		circleP->body.setFillColor(sf::Color::Red);
	}
}

void Game::c2capsuleCollision()
{
	c2Circle circle_circleP;
	int c2x=circleP->x+circleP->r;
	int c2y=circleP->y+circleP->r;
	circle_circleP.p=c2V(c2x,c2y);
	circle_circleP.r=circleP->r;

	c2Capsule capsule_line;
	capsule_line.a=c2V(line->x,line->y);
	capsule_line.b=c2V(line->x+line->w,line->y);
	capsule_line.r=circleP->r;
	circleE->x=capsule_line.a.x-circleE->r;
	circleE->y=capsule_line.a.y-circleE->r;
	circleE->setPosition();
	circleE->body.setFillColor(sf::Color::Transparent);
	circleE->body.setOutlineColor(sf::Color::Yellow);
	circleE->body.setOutlineThickness(1.0f);

	circleCapsule->x=capsule_line.b.x-circleE->r;
	circleCapsule->y=capsule_line.b.y-circleE->r;
	circleCapsule->setPosition();
	circleCapsule->body.setFillColor(sf::Color::Transparent);
	circleCapsule->body.setOutlineColor(sf::Color::Yellow);
	circleCapsule->body.setOutlineThickness(1.0f);

	rectangleCapsule->body.setFillColor(sf::Color::Transparent);
	rectangleCapsule->body.setOutlineColor(sf::Color::Yellow);
	rectangleCapsule->body.setOutlineThickness(1.0f);


	if(c2CircletoCapsule(circle_circleP, capsule_line))
	{
		cout << "Circle and capsule are in Collision" << endl;
		circleP->body.setFillColor(sf::Color::Blue);
	} 
	else
	{
		cout << "No Collision" << endl;
		circleP->body.setFillColor(sf::Color::Red);
	}

	c2AABB aabb_player;
	aabb_player.min = c2V(player->m_sprite.getPosition().x,player->m_sprite.getPosition().y); 
	aabb_player.max = c2V(player->m_sprite.getPosition().x + player->m_sprite.getGlobalBounds().width, player->m_sprite.getPosition().y + player->m_sprite.getGlobalBounds().height);
	

	if(c2AABBtoCapsule(aabb_player, capsule_line))
	{
		cout << "aabb and capsule are in Collision" << endl;
		player->m_boundingBox.setOutlineColor(sf::Color::Blue);
	}
	else
	{
		cout << "No Collision" << endl;
		player->m_boundingBox.setOutlineColor(sf::Color::Green);
	}

}

void Game::c2AABBcollision()
{
	c2AABB aabb_npc;
	aabb_npc.min = c2V(npc->m_sprite.getPosition().x, npc->m_sprite.getPosition().y); //lft top
	aabb_npc.max = c2V(npc->m_sprite.getPosition().x +
					npc->m_sprite.getGlobalBounds().width, 
					npc->m_sprite.getPosition().y +
					npc->m_sprite.getGlobalBounds().height); //right bottom
	
	c2Circle circle_circleP;
	int c2x=circleP->x+circleP->r;
	int c2y=circleP->y+circleP->r;
	circle_circleP.p=c2V(c2x,c2y);
	circle_circleP.r=circleP->r;

	if(c2CircletoAABB(circle_circleP, aabb_npc))
	{
		cout << "circle and aabb are in Collision" << endl;
		circleP->body.setFillColor(sf::Color::Blue);
	}
	else
	{
		cout << "No Collision" << endl;
		circleP->body.setFillColor(sf::Color::Red);
	}

	c2Capsule capsule_line;
	capsule_line.a=c2V(line->x,line->y);
	capsule_line.b=c2V(line->x+line->w,line->y);
	capsule_line.r=circleCapsuleR->r;
	circleCapsuleR->x=capsule_line.a.x-circleCapsuleR->r;
	circleCapsuleR->y=capsule_line.a.y-circleCapsuleR->r;
	circleCapsuleR->setPosition();
	circleCapsuleR->body.setFillColor(sf::Color::Transparent);
	circleCapsuleR->body.setOutlineColor(sf::Color::Yellow);
	circleCapsuleR->body.setOutlineThickness(1.0f);

	circleCapsule->x=capsule_line.b.x-circleCapsule->r;
	circleCapsule->y=capsule_line.b.y-circleCapsule->r;
	circleCapsule->setPosition();
	circleCapsule->body.setFillColor(sf::Color::Transparent);
	circleCapsule->body.setOutlineColor(sf::Color::Yellow);
	circleCapsule->body.setOutlineThickness(1.0f);

	rectangleCapsule->body.setFillColor(sf::Color::Transparent);
	rectangleCapsule->body.setOutlineColor(sf::Color::Yellow);
	rectangleCapsule->body.setOutlineThickness(1.0f);
	
	if(c2AABBtoCapsule(aabb_npc, capsule_line))
	{
		cout << "aabb and capsule are in Collision" << endl;
		circleCapsuleR->body.setOutlineColor(sf::Color::Blue);
		circleCapsule->body.setOutlineColor(sf::Color::Blue);
		rectangleCapsule->body.setOutlineColor(sf::Color::Blue);
	}
	else
	{
		cout << "No Collision" << endl;
		circleCapsuleR->body.setOutlineColor(sf::Color::Yellow);
		circleCapsule->body.setOutlineColor(sf::Color::Yellow);
		rectangleCapsule->body.setOutlineColor(sf::Color::Yellow);
	}
	
}

c2Ray pointsToRay(sf::Vector2f t_1, sf::Vector2f t_2)
{
    //std::cout << t_1.x << " " << t_1.y << "\t" << t_2.x << " " << t_2.y << "\n";
    // c2v p;   c2v d;   float t; // d is normalised vector, t is length
    c2Ray i;
    c2v u;
    u.x = t_1.x;
    u.y = t_1.y;
    i.p = u;

    // normalising t_2
    float dist = sqrtf(t_2.x * t_2.x + t_2.y * t_2.y);
    u.x = t_2.x / dist;
    u.y = t_2.y / dist;
    i.d = u;
    i.t = dist;

    return i;
} 

void Game::c2rayCollision()
{
	/*
	c2Ray ray_line; //position, direction(normalised), distance along d from position p to find endpoint of ray
	ray_line.p=c2V(line->x,line->y);
	float magnitude=sqrtf(line->w*line->w + line->h*line->h);
	ray_line.d=c2V(1,1);//(line->x+line->w)/magnitude, (line->y+line->h)/magnitude);
	ray_line.t=magnitude;
	c2Raycast raycast_raycast; //time of impact, normal of surface at impact (unit length)
	raycast_raycast.t=0;
	raycast_raycast.n=c2V(0, 0);
	c2Raycast* out=&raycast_raycast;

	std::cout<<"magnitude: "<<ray_line.t<<"\n";
	std::cout<<"x2: "<<ray_line.d.x<<"\n";
	*/

	c2Ray ray_line;//=pointsToRay(rayLine->a,rayLine->b);
	ray_line.p=c2V(rayLine->a.x,rayLine->a.y);
	float magnitude=sqrtf((rayLine->a.x - rayLine->b.x)*(rayLine->a.x - rayLine->b.x) + (rayLine->a.y - rayLine->b.y)*(rayLine->a.y - rayLine->b.y));
	ray_line.d=c2V(rayLine->b.x/magnitude, rayLine->b.y/magnitude);
	ray_line.t=magnitude;
	c2Raycast raycast_raycast; //time of impact, normal of surface at impact (unit length)
	raycast_raycast.t=0;
	raycast_raycast.n=c2V(0, 0);
	c2Raycast* out=&raycast_raycast;

	c2Circle circle_circleP;
	int c2x=circleP->x+circleP->r;
	int c2y=circleP->y+circleP->r;
	circle_circleP.p=c2V(c2x,c2y);
	circle_circleP.r=circleP->r;

	if(c2RaytoCircle(ray_line, circle_circleP, out))
	{
		cout << "ray and circle are in Collision" << endl;
		circleP->body.setFillColor(sf::Color::Blue);
	}
	else
	{
		cout << "No Collision" << endl;
		circleP->body.setFillColor(sf::Color::Red);
	}

	c2AABB aabb_player;
	aabb_player.min = c2V(player->m_sprite.getPosition().x,player->m_sprite.getPosition().y); 
	aabb_player.max = c2V(player->m_sprite.getPosition().x + player->m_sprite.getGlobalBounds().width, player->m_sprite.getPosition().y + player->m_sprite.getGlobalBounds().height);

	if(c2RaytoAABB(ray_line, aabb_player, out))
	{
		cout << "ray and aabb are in Collision" << endl;
		player->m_boundingBox.setOutlineColor(sf::Color::Blue);
	}
	else
	{
		cout << "No Collision" << endl;
		player->m_boundingBox.setOutlineColor(sf::Color::Green);
	}

	c2Capsule capsule_line;
	capsule_line.a=c2V(line->x,line->y);
	capsule_line.b=c2V(line->x+line->w,line->y);
	capsule_line.r=circleCapsuleR->r;
	circleCapsuleR->x=capsule_line.a.x-circleCapsuleR->r;
	circleCapsuleR->y=capsule_line.a.y-circleCapsuleR->r;
	circleCapsuleR->setPosition();
	circleCapsuleR->body.setFillColor(sf::Color::Transparent);
	circleCapsuleR->body.setOutlineColor(sf::Color::Yellow);
	circleCapsuleR->body.setOutlineThickness(1.0f);

	circleCapsule->x=capsule_line.b.x-circleCapsule->r;
	circleCapsule->y=capsule_line.b.y-circleCapsule->r;
	circleCapsule->setPosition();
	circleCapsule->body.setFillColor(sf::Color::Transparent);
	circleCapsule->body.setOutlineColor(sf::Color::Yellow);
	circleCapsule->body.setOutlineThickness(1.0f);

	rectangleCapsule->body.setFillColor(sf::Color::Transparent);
	rectangleCapsule->body.setOutlineColor(sf::Color::Yellow);
	rectangleCapsule->body.setOutlineThickness(1.0f);
	
	if(c2RaytoCapsule(ray_line, capsule_line, out))
	{
		cout << "ray and capsule are in Collision" << endl;
		circleCapsuleR->body.setOutlineColor(sf::Color::Blue);
		circleCapsule->body.setOutlineColor(sf::Color::Blue);
		rectangleCapsule->body.setOutlineColor(sf::Color::Blue);
	}
	else
	{
		cout << "No Collision" << endl;
		circleCapsuleR->body.setOutlineColor(sf::Color::Yellow);
		circleCapsule->body.setOutlineColor(sf::Color::Yellow);
		rectangleCapsule->body.setOutlineColor(sf::Color::Yellow);
	}
}

void Game::drawCapsule()
{
	window->draw(circleCapsule->body);
	window->draw(circleCapsuleR->body);
	window->draw(rectangleCapsule->body);
	window->draw(line->body);

}

void Game::draw()
{
	window->clear();
	switch(currentGameState)
	{
		case GameState::BOUNDING:
			window->draw(player->m_boundingBox);
			window->draw(player->m_sprite);
			window->draw(npc->m_sprite);
			break;
		case GameState::C2CIRCLE:
			window->draw(circleP->body);
			window->draw(circleE->body);
			break;
		case GameState::C2CAPSULE:
			window->draw(line->body);
			window->draw(circleP->body);
			window->draw(circleE->body);
			window->draw(circleCapsule->body);
			window->draw(rectangleCapsule->body);
			window->draw(player->m_boundingBox);
			break;
		case GameState::C2AABB:
			window->draw(npc->m_boundingBox);
			window->draw(circleP->body);
			drawCapsule();
			break;
		case GameState::C2RAY:
			if(displayCapsule)
			{
				drawCapsule();
			}
			else
			{
				window->draw(circleP->body);
				window->draw(player->m_boundingBox);
			}
			rayLine->draw(window);
			break;
	}
	
	
	//window->draw(player->m_boundingBox);
	//player->draw();
	//npc->draw();
	window->display();
}


