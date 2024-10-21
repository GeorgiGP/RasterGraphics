#include "../Commands/Specific/SessionInfo.h"

SessionInfo::SessionInfo(ListOfSessions *& list) : Manage(list)
{
}

void SessionInfo::execute()
{
	receiver->sessionInfo();
}
