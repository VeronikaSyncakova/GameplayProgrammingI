#include <./include/GameObject.h>

GameObject::GameObject(){
}

GameObject::~GameObject(){
}

void GameObject::initialize(String image){
	if (!texture.loadFromFile(image + ".png"))
	{
		std::cout << "Image file not found";
	}

	texture.setSmooth(true);
	sprite.setTexture(texture); 
	sprite.setPosition(sf::Vector2f(position.x, position.y));
	jumping=0;
	running=false;
	crouching=0;
}

void GameObject::update()
{
	sprite.setPosition(this->position);
	if(jumping<120)
	{
		this->sprite.setScale(1.5f,1.5f);
		jumping++;
	}
	else{
		this->sprite.setScale(1.0f,1.0f);
	}

	if(crouching<240)
	{
		this->sprite.setScale(1.0f,0.5f);
		crouching++;
	}
	else{
		this->sprite.setScale(1.0f,1.0f);
	}
	
}

void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	
}

void GameObject::setPosition(Vector2f position)
{
	this->position = position;
}

Vector2f GameObject::getPosition()
{
	return this->position;
}

void GameObject::moveUp()
{
	if(running)
	{
		this->position.y -= 10;
	}
	else
	{
		this->position.y -= 5;
	}
}

void GameObject::moveDown()
{
	if(running)
	{
		this->position.y += 10;
	}
	else
	{
		this->position.y += 5;
	}
}

void GameObject::moveLeft()
{
	if (running)
	{
		this->position.x -= 10;
	}
	else
	{
		this->position.x -= 5;
	}
}

void GameObject::moveRight()
{
	if (running)
	{
		this->position.x += 10;
	}
	else
	{
		this->position.x += 5;
	}
}

void GameObject::jump()
{
	std::cout<<"jumping\n";
	/*
	if (this->sprite.getScale()==sf::Vector2f(1.0f,1.0f))
	{
		this->sprite.setScale(1.5f,1.5f);
	}
	else
	{
		sprite.setScale(1.0f,1.0f);
	}*/
	jumping=0;
	//this->sprite.setScale(1.5f,1.5f);
	//this->sprite.setScale(1.0f,1.0f);

}

Vector2f GameObject::getScale()
{
	return this->sprite.getScale();
}

void GameObject::setScale(Vector2f t_scale)
{
	this->sprite.setScale(t_scale);
}

void GameObject::run()
{
	std::cout<<"running\n";
	if (!running)
	{
		running=true;
	}
	else
	{
		running=false;
	}
}

void GameObject::crouch()
{
	std::cout<<"crouching\n";
	crouching=0;
}

void GameObject::attack()
{
	std::cout<<"attacking\n";
	
}

void GameObject::shield()
{
	std::cout<<"shielding\n";
	
}