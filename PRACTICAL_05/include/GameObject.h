#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject();
	~GameObject();
	virtual void initialize();
	void update();
	void draw();
	

	// This is really bad but to keep example as simple as possible 
	// these attributes are public

	float x; // x position
	float y; // y position
	float w; // width
	float h; // height
	float r; // radius
	sf::RectangleShape m_boundingBox;;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};
#endif