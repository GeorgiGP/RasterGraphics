#include "SwitchSession.h"

SwitchSession::SwitchSession(ListOfSessions *& list, unsigned id) : Manage(list), id(id)
{
}

void SwitchSession::execute()
{
	if (!receiver->switchSession(id))
	{
		receiver->warningIndex();
	}
}
