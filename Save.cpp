#include "Save.h"

Save::Save(ListOfSessions *& list) : Manage(list)
{
}

void Save::execute()
{
	receiver->save();
}
