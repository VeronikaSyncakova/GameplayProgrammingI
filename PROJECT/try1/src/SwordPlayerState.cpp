#include <Events.h>

#include <SwordPlayerState.h>

#include <RunRightPlayerState.h>
#include <IdlePlayerState.h>
#include <DiedPlayerState.h>

PlayerState* SwordPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::ATTACK_STOP_EVENT)
	{
		DEBUG_MSG("SwordPlayerState -> IdlePlayerState");
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("SwordPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void SwordPlayerState::update(Player& player) {
	DEBUG_MSG("SwordPlayerState::update");
	DEBUG_MSG(typeid(player).name());
}

void SwordPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering SwordPlayerState");
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
void SwordPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting SwordPlayerState");
	DEBUG_MSG(typeid(player).name());
}