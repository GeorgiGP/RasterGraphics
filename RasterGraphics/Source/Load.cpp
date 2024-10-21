#include "../Commands/Specific/Load.h"
#include "../Factories/FactoryImage.h"

Load::Load(ListOfSessions*& receiver) : Manage(receiver)
{}

void Load::addImage(const char * imgName)
{
	if (!imgName)
	{
		throw std::nullptr_t();
	}
	Image* image = factoryImage(imgName);
	if (image)
	{
		if (!images.pushBack(image)) //can't be added, full maxCapacity (rare)
		{
			delete image;
			image = nullptr; 
		}
	}
}

void Load::execute()
{
	if (images.isEmpty())
	{
		throw std::logic_error("Add at least one valid image!");
	}
	if (!receiver)
	{
		receiver = new ListOfSessions();
	}
	if (!receiver->loadSession())
	{
		throw std::logic_error("List is full of Sessions!");
	}
	while (!images.isEmpty())
	{
		receiver->addImage(images.peek());
		images.popFirst();
	}
}

