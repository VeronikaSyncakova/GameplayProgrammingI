#include <Events.h>

#include <PunchPlayerState.h>
#include <IdlePlayerState.h>



PlayerState* PunchPlayerState::handleInput(gpp::Events& input) {
    if (input.getCurrent()== gpp::Events::Event::PUNCH_STOP_EVENT)
    {
        return new IdlePlayerState();
    }
	return nullptr;
}

void PunchPlayerState::update(Player& player) {
	DEBUG_MSG(typeid(player).name());
	/*
	if (player.getAnimatedSprite().getPlayed())
	{
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new IdlePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp;
	}
	*/
}

void PunchPlayerState::enter(Player& player) 
{
	DEBUG_MSG("Entering KickPlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(sf::IntRect(70, 4709, 113, 200));
	player.getAnimatedSprite().addFrame(sf::IntRect(231, 4709, 113, 200));
	
	player.getAnimatedSprite().setTime(seconds(0.3f));
}

void PunchPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting KickPlayerState");
	DEBUG_MSG(typeid(player).name());
}