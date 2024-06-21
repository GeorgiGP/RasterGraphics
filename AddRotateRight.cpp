#include "AddRotateRight.h"

AddRotateRight::AddRotateRight(ListOfSessions *& list) : Manage(list)
{
}

void AddRotateRight::execute()
{
	Image* img = nullptr;
	RotateRight* add = new RotateRight(img);
	receiver->addTransformation(add);
	delete add;
}
