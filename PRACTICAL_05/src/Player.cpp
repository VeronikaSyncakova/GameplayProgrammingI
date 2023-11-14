#include <./include/Player.h>

Player::Player(){};
Player::~Player(){};

void Player::initialize()
{
	//cout << "Player initialize" << endl;
	x=0;
	y=0;
	r=0;
	m_texture.loadFromFile(".//images//player//Player.png");
	m_sprite.setTexture(m_texture);
	m_boundingBox.setSize(sf::Vector2f(m_sprite.getGlobalBounds().width,m_sprite.getGlobalBounds().height));
	m_boundingBox.setPosition(0.f,0.f);
	m_boundingBox.setOutlineColor(sf::Color::Green);
	m_boundingBox.setFillColor(sf::Color::Transparent);
	m_boundingBox.setOutlineThickness(3.0f);

	w=m_sprite.getGlobalBounds().width;
	h=m_sprite.getGlobalBounds().height;
}
void Player::update()
{
	//cout << "Player updating" << endl;
}
void Player::draw()
{
	//cout << "Player drawing" << endl;
}

void Player::moveUp()
{
	if(y>0)
	{
		y-=3;
	}
	m_sprite.setPosition(sf::Vector2f(x,y));
	m_boundingBox.setPosition(m_sprite.getPosition());
}
void Player::moveDown()
{
	if(y+h<600)
	{
		y+=3;
	}
	m_sprite.setPosition(sf::Vector2f(x,y));
	m_boundingBox.setPosition(m_sprite.getPosition());
}
void Player::moveRight()
{
	if(x+w<800)
	{
		x+=3;
	}
	m_sprite.setPosition(sf::Vector2f(x,y));
	m_boundingBox.setPosition(m_sprite.getPosition());
}
void Player::moveLeft()
{
	if(x>0)
	{
		x-=3;
	}
	m_sprite.setPosition(sf::Vector2f(x,y));
	m_boundingBox.setPosition(m_sprite.getPosition());
}
