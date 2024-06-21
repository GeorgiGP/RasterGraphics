#include "AddRotateLeft.h"

AddRotateLeft::AddRotateLeft(ListOfSessions *& list) : Manage(list)
{
}

void AddRotateLeft::execute()
{
	Image* img = nullptr;
	RotateLeft* add = new RotateLeft(img);
	receiver->addTransformation(add);
	delete add;
}
