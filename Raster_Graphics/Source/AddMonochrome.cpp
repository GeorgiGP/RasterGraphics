#include "../Commands/Specific/AddMonochrome.h"

AddMonochrome::AddMonochrome(ListOfSessions *& list) : Manage(list)
{
}

void AddMonochrome::execute()
{
	Image* img = nullptr;
	Monochrome* add = new Monochrome(img);
	receiver->addTransformation(add);
	delete add;
}
