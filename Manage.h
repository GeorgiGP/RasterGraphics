#pragma once
#include "Command.h"
#include "ListOfSessions.h"

class Manage : public Command
{
protected:
	ListOfSessions*& receiver;
public:

	Manage(ListOfSessions*& receiver);
	~Manage();
};

