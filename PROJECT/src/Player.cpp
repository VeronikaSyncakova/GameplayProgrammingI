#include <Player.h>

Player::Player(const AnimatedSprite& sprite, sf::Vector2f t_position) : m_animated_sprite(sprite)
{
	m_circle.setCircle(20,t_position);
	m_health=100;
	// Set the Player to Default to IdlePlayer State 
	// and Enter that State
	m_state = new IdlePlayerState();
	m_state->enter(*this);
}

Player::~Player()
{
	DEBUG_MSG("~Player()");
}

void Player::handleInput(gpp::Events input) {
	PlayerState * state = m_state->handleInput(input);

	if (state != NULL) {
		m_state->exit(*this);
		delete m_state;
		m_state = state;
		m_state->enter(*this);
	}
}

void Player::update() {
	m_animated_sprite.update();
	m_state->update(*this);
}

void Player::updateCircle(int direction)
{
	m_circle.moveCircle(direction);
}

void Player::calculateHealth(Player& enemy)
{
	if (m_state->getCurrentState()==gpp::Events::Event::PUNCH_START_EVENT)
	{
		if(enemy.getPlayerState()->getCurrentState()==gpp::Events::Event::PUNCH_START_EVENT)
		{
			m_health-=20;
			enemy.m_health-=20;
		}
		else if(enemy.getPlayerState()->getCurrentState()==gpp::Events::Event::KICK_START_EVENT)
		{
			m_health-=30;
		}
		else if(enemy.getPlayerState()->getCurrentState()==gpp::Events::Event::BLOCK_START_EVENT)
		{
			m_health+=10;
		}
	}
	else if (m_state->getCurrentState()==gpp::Events::Event::BLOCK_START_EVENT)
	{
		if(enemy.getPlayerState()->getCurrentState()==gpp::Events::Event::PUNCH_START_EVENT)
		{
			m_health+=10;
		}
		else if(enemy.getPlayerState()->getCurrentState()==gpp::Events::Event::KICK_START_EVENT)
		{
			m_health-=30;
			
		}
		else if(enemy.getPlayerState()->getCurrentState()==gpp::Events::Event::BLOCK_START_EVENT)
		{
			m_health-=10;
			enemy.m_health-=10;
		}
	}
	else if (m_state->getCurrentState()==gpp::Events::Event::KICK_START_EVENT)
	{
		if(enemy.getPlayerState()->getCurrentState()==gpp::Events::Event::PUNCH_START_EVENT)
		{
			m_health+=20;
			
		}
		else if(enemy.getPlayerState()->getCurrentState()==gpp::Events::Event::KICK_START_EVENT)
		{
			m_health-=10;
			enemy.m_health-=10;
		}
		else if(enemy.getPlayerState()->getCurrentState()==gpp::Events::Event::BLOCK_START_EVENT)
		{
			m_health+=30;
			
		}
	}
}


Circle Player::getCircle()
{
	return m_circle;
}


AnimatedSprite& Player::getAnimatedSprite() {
	return m_animated_sprite;
}

AnimatedSprite& Player::getAnimatedSpriteFrame() {
	int frame = m_animated_sprite.getCurrentFrame();
	m_animated_sprite.setTextureRect(m_animated_sprite.getFrame(frame));
	return m_animated_sprite;
}

void Player::setAnimatedSprite(AnimatedSprite& animated_sprite) {
	this->m_animated_sprite = animated_sprite;
}

PlayerState* Player::getPlayerState() { return this->m_state; }

void Player::setPlayerState(PlayerState* state) { this->m_state = state; }

void Player::setCirclePosition(sf::Vector2f t_position)
{
	m_circle.setPosition(t_position);
}

int Player::getHealth()
{
	return m_health;
}
