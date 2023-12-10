#ifndef CONCRETE_COMMANDS_H
#define CONCRETE_COMMANDS_H

#include <./include/Command.h>

class MoveUpCommand : public Command
{
public:
	virtual void execute(GameObject *gameobject, gpp::Events& input)
	{
		previous = gameobject->getPosition();
		input.setCurrent(gpp::Events::Event::SHIELD_START_EVENT);
	}
	virtual void undo(GameObject *gameobject)
	{
		gameobject->setPosition(previous);
	}
	Command *copy()
	{
		return new MoveUpCommand(*this);
	}

private:
	Vector2f previous;
};

class MoveDownCommand : public Command
{
public:
	virtual void execute(GameObject *gameobject, gpp::Events& input)
	{
		previous = gameobject->getPosition();
		//gameobject->moveDown();
		input.setCurrent(gpp::Events::Event::SWORD_START_EVENT);
	}
	virtual void undo(GameObject *gameobject)
	{
		gameobject->setPosition(previous);
	}
	Command *copy()
	{
		return new MoveDownCommand(*this);
	}

private:
	Vector2f previous;
};

class MoveLeftCommand : public Command
{
public:
	virtual void execute(GameObject *gameobject, gpp::Events& input)
	{
		previous = gameobject->getPosition();
		//gameobject->moveLeft();
		input.setCurrent(gpp::Events::Event::SWORD_START_EVENT);
	}
	virtual void undo(GameObject *gameobject)
	{
		gameobject->setPosition(previous);
	}
	Command *copy()
	{
		return new MoveLeftCommand(*this);
	}

private:
	Vector2f previous;
};

class MoveRightCommand : public Command
{
public:
	virtual void execute(GameObject *gameobject, gpp::Events& input)
	{
		previous = gameobject->getPosition();
		//gameobject->moveRight();
		input.setCurrent(gpp::Events::Event::SWORD_START_EVENT);
	}
	virtual void undo(GameObject *gameobject)
	{
		gameobject->setPosition(previous);
	}
	Command *copy()
	{
		return new MoveRightCommand(*this);
	}

private:
	Vector2f previous;
};

class JumpCommand : public Command
{
public:
	virtual void execute(GameObject *gameobject, gpp::Events& input)
	{
		previous = gameobject->getPosition();
		input.setCurrent(gpp::Events::Event::SWORD_START_EVENT);
		
	}
	virtual void undo(GameObject *gameobject)
	{
		gameobject->setPosition(previous);
	}
	Command *copy()
	{
		return new JumpCommand(*this);
	}

private:
	Vector2f previous;
	Vector2f scale;
};

class RunCommand : public Command
{
public:
	virtual void execute(GameObject *gameobject, gpp::Events& input)
	{
		previous = gameobject->getPosition();
		//gameobject->run();
		input.setCurrent(gpp::Events::Event::SWORD_START_EVENT);
	}
	virtual void undo(GameObject *gameobject)
	{
		gameobject->setPosition(previous);
	}
	Command *copy()
	{
		return new RunCommand(*this);
	}

private:
	Vector2f previous;
};

class CrouchCommand : public Command
{
public:
	virtual void execute(GameObject *gameobject, gpp::Events& input)
	{
		previous = gameobject->getPosition();
		//gameobject->crouch();
		input.setCurrent(gpp::Events::Event::SWORD_START_EVENT);
	}
	virtual void undo(GameObject *gameobject)
	{
		//gameobject->setPosition(previous);
		//gameobject->crouch();
		gameobject->setPosition(previous);
	}
	Command *copy()
	{
		return new CrouchCommand(*this);
	}

private:
	Vector2f previous;
};

class AttackCommand : public Command
{
public:
	virtual void execute(GameObject *gameobject, gpp::Events& input)
	{
		previous = gameobject->getPosition();
		//gameobject->attack();
		input.setCurrent(gpp::Events::Event::BAT_START_EVENT);
	}
	virtual void undo(GameObject *gameobject)
	{
		//gameobject->setPosition(previous);
		//gameobject->attack();
		gameobject->setPosition(previous);
	}
	Command *copy()
	{
		return new AttackCommand(*this);
	}

private:
	Vector2f previous;
};

class ShieldCommand : public Command
{
public:
	virtual void execute(GameObject *gameobject, gpp::Events& input)
	{
		previous = gameobject->getPosition();
		//gameobject->shield();
		input.setCurrent(gpp::Events::Event::SWORD_START_EVENT);
	}
	virtual void undo(GameObject *gameobject)
	{
		//gameobject->setPosition(previous);
		//gameobject->shield();
		gameobject->setPosition(previous);
	}
	Command *copy()
	{
		return new ShieldCommand(*this);
	}

private:
	Vector2f previous;
};

#endif // !CONCRETE_COMMANDS_H