#ifndef EVENT_H
#define EVENT_H

#include <iostream>

namespace gpp {
	class Events
	{
	public:
		Events();
		~Events();

		enum class Event
		{
			NONE,
			DIED_EVENT,
			REVIVED_EVENT,
			KICK_START_EVENT,
			KICK_STOP_EVENT,
			BLOCK_START_EVENT,
			BLOCK_STOP_EVENT,
			PUNCH_START_EVENT,
			PUNCH_STOP_EVENT,
			Count
		};

		void setCurrent(Event);
		Event getCurrent();
		void setRandom();

	private:
		Event m_current;
	};
}

#endif
