#include <Events.h>

#include <BatPlayerState.h>

#include <RunRightPlayerState.h>
#include <IdlePlayerState.h>
#include <DiedPlayerState.h>

PlayerState* BatPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::ATTACK_STOP_EVENT)
	{
		DEBUG_MSG("BatPlayerState -> IdlePlayerState");
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("BatPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void BatPlayerState::update(Player& player) {
	DEBUG_MSG("BatPlayerState::update");
	DEBUG_MSG(typeid(player).name());
}

void BatPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering BatPlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(sf::IntRect(0, 0, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(536, 0, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(1072, 0, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(0, 495, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(536, 495, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(1072, 495, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(0, 990, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(536, 990, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(1072, 990, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(0, 1485, 536, 495));

	player.getAnimatedSprite().setTime(seconds(0.03f));
}
void BatPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting BatPlayerState");
	DEBUG_MSG(typeid(player).name());
}