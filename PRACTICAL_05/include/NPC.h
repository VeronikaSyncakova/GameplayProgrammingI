#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <./include/GameObject.h>

using namespace std;

class NPC : public GameObject
{
public:
	NPC();
	~NPC();
	void initialize();
	void update();
	void draw();

	sf::RectangleShape m_boundingBox;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};
#endif