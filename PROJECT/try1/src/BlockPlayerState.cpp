#include <Events.h>

#include <BlockPlayerState.h>
#include <IdlePlayerState.h>



PlayerState* BlockPlayerState::handleInput(gpp::Events& input) {
    if (input.getCurrent()== gpp::Events::Event::BLOCK_STOP_EVENT)
    {
        return new IdlePlayerState();
    }
	return nullptr;
}

void BlockPlayerState::update(Player& player) {
	DEBUG_MSG(typeid(player).name());
}

void BlockPlayerState::enter(Player& player) 
{
	DEBUG_MSG("Entering KickPlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(sf::IntRect(48, 4512, 96, 192));
	player.getAnimatedSprite().addFrame(sf::IntRect(208, 4512, 96, 192));
	
	player.getAnimatedSprite().setTime(seconds(0.3f));
}

void BlockPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting KickPlayerState");
	DEBUG_MSG(typeid(player).name());
}