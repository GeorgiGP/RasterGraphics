#include "Undo.h"

Undo::Undo(ListOfSessions *& list) : Manage(list)
{
}

void Undo::execute()
{
	receiver->undo();
}
