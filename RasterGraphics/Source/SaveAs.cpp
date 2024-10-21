#include "../Commands/Specific/SaveAs.h"
#pragma warning(disable: 4996)
SaveAs::SaveAs(ListOfSessions *& list, const char* withName) : Manage(list)
{
	if (!withName)
	{
		throw std::nullptr_t();
	}
	this->withName = new char[strlen(withName) + 1];
	strcpy(this->withName, withName);
}

void SaveAs::execute()
{
	receiver->saveAsFirstImage(withName);
}

SaveAs::~SaveAs()
{
	delete[] this->withName;
	this->withName = nullptr;
}
