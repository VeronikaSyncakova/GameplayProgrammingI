#include <Events.h>

#include <KickPlayerState.h>
#include <IdlePlayerState.h>



PlayerState* KickPlayerState::handleInput(gpp::Events& input) {
    if (input.getCurrent()== gpp::Events::Event::KICK_STOP_EVENT)
    {
        return new IdlePlayerState();
    }
	return nullptr;
}

void KickPlayerState::update(Player& player) {
	DEBUG_MSG(typeid(player).name());
	if (player.getAnimatedSprite().getPlayed())
	{
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new IdlePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp;
	}
}

void KickPlayerState::enter(Player& player) 
{
	DEBUG_MSG("Entering KickPlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(sf::IntRect(37, 4916, 117, 200));
	player.getAnimatedSprite().addFrame(sf::IntRect(223, 4916, 117, 200));
	/*player.getAnimatedSprite().addFrame(sf::IntRect(4364, 0, 232, 439));
	player.getAnimatedSprite().addFrame(sf::IntRect(3900, 439, 232, 439));
	player.getAnimatedSprite().addFrame(sf::IntRect(4132, 439, 232, 439));
	player.getAnimatedSprite().addFrame(sf::IntRect(4364, 439, 232, 439));
	player.getAnimatedSprite().addFrame(sf::IntRect(3900, 878, 232, 439));
	player.getAnimatedSprite().addFrame(sf::IntRect(4132, 878, 232, 439));
	player.getAnimatedSprite().addFrame(sf::IntRect(4364, 878, 232, 439));
	player.getAnimatedSprite().addFrame(sf::IntRect(3900, 1317, 232, 439));
    */
	
	player.getAnimatedSprite().setTime(seconds(0.3f));
}

void KickPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting KickPlayerState");
	DEBUG_MSG(typeid(player).name());
}