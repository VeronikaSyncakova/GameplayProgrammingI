#include <./include/NPC.h>

NPC::NPC(){};
NPC::~NPC(){};

void NPC::initialize()
{
	//cout << "NPC initialize" << endl;
	x=0;
	y=0;
	r=0;
	m_texture.loadFromFile(".//images//npc//npc.png");
	m_sprite.setTexture(m_texture);
	m_boundingBox.setSize(sf::Vector2f(m_sprite.getGlobalBounds().width,m_sprite.getGlobalBounds().height));
	m_boundingBox.setPosition(0.f,0.f);
	m_boundingBox.setOutlineColor(sf::Color::Green);
	m_boundingBox.setFillColor(sf::Color::Transparent);
	m_boundingBox.setOutlineThickness(1.0f);
	w=m_sprite.getGlobalBounds().width;
	h=m_sprite.getGlobalBounds().height;
}
void NPC::update()
{
	//cout << "NPC updating" << endl;
}
void NPC::draw()
{
	//cout << "NPC drawing" << endl;
}