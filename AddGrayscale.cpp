#include "AddGrayscale.h"

AddGrayscale::AddGrayscale(ListOfSessions *& list) : Manage(list)
{
}

void AddGrayscale::execute()
{
	Image* img = nullptr;
	Grayscale* add = new Grayscale(img);
	receiver->addTransformation(add);
	delete add;
}
