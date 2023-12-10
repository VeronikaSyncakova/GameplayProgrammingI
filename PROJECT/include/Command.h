#ifndef COMMAND_H
#define COMMAND_H

#include <Events.h>

class Command
{
public:
	virtual ~Command() {}
	virtual void execute(gpp::Events& input) = 0;
	virtual void undo(gpp::Events& input) = 0;
	virtual Command* copy() = 0; // used to Copy commands to a list (vector)
};

#endif // !COMMAND_H