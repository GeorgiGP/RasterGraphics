#include "../Commands/Specific/Exit.h"

Exit::Exit(ListOfSessions *& list) : Manage(list)
{
}

void Exit::execute()
{
	delete receiver;
	receiver = nullptr;
}
