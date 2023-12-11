#include <Events.h>

#include <BlockPlayerState.h>
#include <IdlePlayerState.h>
#include <DiedPlayerState.h>



PlayerState* BlockPlayerState::handleInput(gpp::Events& input) {
	/*
    if (input.getCurrent()== gpp::Events::Event::NONE)
    {
        return new IdlePlayerState();
    }
	*/
	return nullptr;
	
}

void BlockPlayerState::update(Player& player) {
	DEBUG_MSG(typeid(player).name());
	if (player.getHealth()<=0)
	{
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new DiedPlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp;
	}
	else if (player.getAnimatedSprite().getPlayed())
	{
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new IdlePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp;
	}
	
}

void BlockPlayerState::enter(Player& player) 
{
	DEBUG_MSG("Entering KickPlayerState");
	m_currentState=gpp::Events::Event::BLOCK_START_EVENT;
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