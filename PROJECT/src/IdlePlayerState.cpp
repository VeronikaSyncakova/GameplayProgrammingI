#include <Events.h>

#include <IdlePlayerState.h>

#include <DiedPlayerState.h>
#include <PunchPlayerState.h>
#include <KickPlayerState.h>
#include <BlockPlayerState.h>



PlayerState* IdlePlayerState::handleInput(gpp::Events& input) {

	if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("IdlePlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	else if( input.getCurrent()== gpp::Events::Event::KICK_START_EVENT)
	{
		DEBUG_MSG("IdlePlayerState -> KickPlayerState");
		return new KickPlayerState();
	}
	else if( input.getCurrent()== gpp::Events::Event::PUNCH_START_EVENT)
	{
		DEBUG_MSG("IdlePlayerState -> PunchPlayerState");
		return new PunchPlayerState();
	}
	else if( input.getCurrent()== gpp::Events::Event::BLOCK_START_EVENT)
	{
		DEBUG_MSG("IdlePlayerState -> BlockPlayerState");
		return new BlockPlayerState();
	}
	return nullptr;

}

void IdlePlayerState::update(Player& player) {
	DEBUG_MSG(typeid(player).name());
}

void IdlePlayerState::enter(Player& player) 
{
	DEBUG_MSG("Entering IdlePlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(sf::IntRect(3900, 0, 232, 439));
	player.getAnimatedSprite().addFrame(sf::IntRect(4132, 0, 232, 439));
	player.getAnimatedSprite().addFrame(sf::IntRect(4364, 0, 232, 439));
	player.getAnimatedSprite().addFrame(sf::IntRect(3900, 439, 232, 439));
	player.getAnimatedSprite().addFrame(sf::IntRect(4132, 439, 232, 439));
	player.getAnimatedSprite().addFrame(sf::IntRect(4364, 439, 232, 439));
	player.getAnimatedSprite().addFrame(sf::IntRect(3900, 878, 232, 439));
	player.getAnimatedSprite().addFrame(sf::IntRect(4132, 878, 232, 439));
	player.getAnimatedSprite().addFrame(sf::IntRect(4364, 878, 232, 439));
	player.getAnimatedSprite().addFrame(sf::IntRect(3900, 1317, 232, 439));
	
	player.getAnimatedSprite().setTime(seconds(0.05f));
}

void IdlePlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting IdlePlayerState");
	DEBUG_MSG(typeid(player).name());
}