#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <./include/GameObject.h>

using namespace std;

class Player : public GameObject
{
public:
	Player();
	~Player();
	void initialize();
	void update();
	void draw();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	sf::RectangleShape m_boundingBox;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	
};
#endif