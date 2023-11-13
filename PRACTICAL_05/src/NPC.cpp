#include <./include/NPC.h>

NPC::NPC(){};
NPC::~NPC(){};

void NPC::initialize()
{
	//cout << "NPC initialize" << endl;
	x=0;
	y=0;
	w=0;
	h=0;
	r=0;
	m_texture.loadFromFile(".//images//npc//npc.png");
	m_sprite.setTexture(m_texture);
}
void NPC::update()
{
	//cout << "NPC updating" << endl;
}
void NPC::draw()
{
	//cout << "NPC drawing" << endl;
}