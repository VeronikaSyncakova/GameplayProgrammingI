#ifndef CONCRETE_COMMANDS_H
#define CONCRETE_COMMANDS_H

#include <Command.h>

class KickCommand : public Command
{
public:
	virtual void execute(gpp::Events& input)
	{
		DEBUG_MSG("gpp::Events::Event::KICK_STAR_EVENT");
		input.setCurrent(gpp::Events::Event::KICK_START_EVENT);
	}
	virtual void undo(gpp::Events& input)
	{
		//will deal with undo later
        DEBUG_MSG("gpp::Events::Event::KICK_STAR_EVENT");
		input.setCurrent(gpp::Events::Event::KICK_START_EVENT);
	}
	Command *copy()
	{
		return new KickCommand(*this);
	}

private:
	Vector2f previous; //not appliable but will change when doing undo
};

class BlockCommand : public Command
{
public:
	virtual void execute(gpp::Events& input)
	{
		DEBUG_MSG("gpp::Events::Event::BLOCK_STAR_EVENT");
		input.setCurrent(gpp::Events::Event::BLOCK_START_EVENT);
	}
	virtual void undo(gpp::Events& input)
	{
		//will deal with undo later
        DEBUG_MSG("gpp::Events::Event::BLOCK_STAR_EVENT");
		input.setCurrent(gpp::Events::Event::BLOCK_START_EVENT);
	}
	Command *copy()
	{
		return new BlockCommand(*this);
	}

private:
	Vector2f previous; //not appliable but will change when doing undo
};

class PunchCommand : public Command
{
public:
	virtual void execute(gpp::Events& input)
	{
		DEBUG_MSG("gpp::Events::Event::PUNCH_STAR_EVENT");
		input.setCurrent(gpp::Events::Event::PUNCH_START_EVENT);
	}
	virtual void undo(gpp::Events& input)
	{
		//will deal with undo later
        DEBUG_MSG("gpp::Events::Event::PUNCH_STAR_EVENT");
		input.setCurrent(gpp::Events::Event::PUNCH_START_EVENT);
	}
	Command *copy()
	{
		return new PunchCommand(*this);
	}

private:
	Vector2f previous; //not appliable but will change when doing undo
};

class RevievedCommand : public Command
{
public:
	virtual void execute(gpp::Events& input)
	{
		DEBUG_MSG("gpp::Events::Event::REVIEVED_EVENT");
		input.setCurrent(gpp::Events::Event::REVIVED_EVENT);
	
	}
	virtual void undo(gpp::Events& input)
	{
		//will deal with undo later
        DEBUG_MSG("gpp::Events::Event::PUNCH_STAR_EVENT");
		input.setCurrent(gpp::Events::Event::REVIVED_EVENT);
	}
	Command *copy()
	{
		return new RevievedCommand(*this);
	}

private:
	Vector2f previous; //not appliable but will change when doing undo
};


#endif