#ifndef PLAYER_H
#define PLAYER_H
#include <Events.h>
#include <PlayerState.h>
#include <AnimatedSprite.h>
#include <stdio.h>
#include <IdlePlayerState.h>
#include <Circle.h>

class Player
{
private:
	PlayerState* m_state;
	AnimatedSprite m_animated_sprite;
	Circle m_circle;
	int m_health;

public:
	Player(const AnimatedSprite&, sf::Vector2f);
	~Player();
	virtual void handleInput(gpp::Events);
	virtual void update();
	AnimatedSprite& getAnimatedSprite();
	AnimatedSprite& getAnimatedSpriteFrame();
	void setAnimatedSprite(AnimatedSprite&);
	PlayerState* getPlayerState();
	void setPlayerState(PlayerState*);
	void updateCircle(int direction);
	Circle getCircle();
	void setCirclePosition(sf::Vector2f t_position);
	void calculateHealth(Player& enemy);
	int getHealth();
	void setHealth(int t_health);
};
#endif

