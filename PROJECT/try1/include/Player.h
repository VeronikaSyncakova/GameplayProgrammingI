#ifndef PLAYER_H
#define PLAYER_H
#include <Events.h>
#include <PlayerState.h>
#include <AnimatedSprite.h>
#include <stdio.h>
#include <IdlePlayerState.h>
#include <GameObject.h>


class Player: public GameObject
{
private:
	PlayerState* m_state;
	AnimatedSprite m_animated_sprite;

public:
	Player(const AnimatedSprite&, sf::Vector2f position);
	~Player();
	virtual void handleInput(gpp::Events);
	virtual void update();
	AnimatedSprite& getAnimatedSprite();
	AnimatedSprite& getAnimatedSpriteFrame();
	void setAnimatedSprite(AnimatedSprite&);
	PlayerState* getPlayerState();
	void setPlayerState(PlayerState*);
};
#endif

