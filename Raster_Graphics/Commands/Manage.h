#pragma once
#include "Command.h"
#include "../Sessions/ListOfSessions.h"

class Manage : public Command
{
protected:
	ListOfSessions*& receiver;
public:

	Manage(ListOfSessions*& receiver);
	~Manage();
};

