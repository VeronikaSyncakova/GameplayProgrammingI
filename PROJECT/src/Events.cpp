#include <Events.h>

gpp::Events::Events()
{
	m_current = Event::NONE;
}
gpp::Events::~Events() {}

void gpp::Events::setCurrent(gpp::Events::Event event) {
	m_current = event;
}

gpp::Events::Event gpp::Events::getCurrent() {
	return m_current;
}

void gpp::Events::setRandom()
{
	int randomCommand=rand()%3;
	if (randomCommand==0)
	{
		m_current=Event::KICK_START_EVENT;
	}
	else if (randomCommand==1)
	{
		m_current=Event::BLOCK_START_EVENT;
	}
	else if (randomCommand==2)
	{
		m_current=Event::PUNCH_START_EVENT;
	}
}
