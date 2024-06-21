#include "CloseSession.h"

CloseSession::CloseSession(ListOfSessions *& list, unsigned id) : Manage(list), id(id)
{
}

void CloseSession::execute()
{
	receiver->closeSession(id);
}
