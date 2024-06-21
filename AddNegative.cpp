#include "AddNegative.h"

AddNegative::AddNegative(ListOfSessions *& list) : Manage(list)
{
}

void AddNegative::execute()
{
	Image* img = nullptr;
	Negative* add = new Negative(img);
	receiver->addTransformation(add);
	delete add;
}
