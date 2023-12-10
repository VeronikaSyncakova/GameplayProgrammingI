#include <Events.h>

#include <ShieldPlayerState.h>

#include <RunRightPlayerState.h>
#include <IdlePlayerState.h>
#include <DiedPlayerState.h>

PlayerState* ShieldPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::ATTACK_STOP_EVENT)
	{
		DEBUG_MSG("AttackPlayerState -> IdlePlayerState");
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("AttackPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void ShieldPlayerState::update(Player& player) {
	DEBUG_MSG("ShieldPlayerState::update");
	DEBUG_MSG(typeid(player).name());
}

void ShieldPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering ShieldPlayerState");
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
void ShieldPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting ShieldPlayerState");
	DEBUG_MSG(typeid(player).name());
}