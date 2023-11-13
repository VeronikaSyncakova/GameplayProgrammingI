#include <./include/Player.h>

Player::Player(){};
Player::~Player(){};

void Player::initialize()
{
	//cout << "Player initialize" << endl;
	x=0;
	y=0;
	w=0;
	h=0;
	r=0;
	m_texture.loadFromFile(".//images//player//Player.png");
	m_sprite.setTexture(m_texture);
	m_boundingBox.setSize(sf::Vector2f(m_sprite.getGlobalBounds().width,m_sprite.getGlobalBounds().height));
	m_boundingBox.setPosition(0.f,0.f);
	m_boundingBox.setOutlineColor(sf::Color::Green);
	m_boundingBox.setFillColor(sf::Color::Transparent);
	m_boundingBox.setOutlineThickness(3.0f);
}
void Player::update()
{
	//cout << "Player updating" << endl;
}
void Player::draw()
{
	//cout << "Player drawing" << endl;
}
