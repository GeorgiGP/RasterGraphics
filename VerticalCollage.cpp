#include "VerticalCollage.h"
#pragma warning(disable: 4996)
VerticalCollage::VerticalCollage(ListOfSessions *& list, Image * lhs, Image * rhs, const char * collageFileName) : Manage(list), lhs(lhs), rhs(rhs)
{
	if (!collageFileName)
	{
		delete lhs;
		delete rhs;
		throw std::nullptr_t();
	}
	this->collageFileName = new char[strlen(collageFileName) + 1];
	strcpy(this->collageFileName, collageFileName);
}

void VerticalCollage::execute()
{
	if (!lhs || !rhs)
	{
		throw std::exception("At least one of the images is unvalid!");
	}
	if (!collageFileName[0])
	{
		throw std::logic_error("Must add fileName!");
	}
	Image* result = lhs->verticalCollage(rhs, collageFileName);
	receiver->addImage(result);
	delete result;
	result = nullptr;
}

VerticalCollage::~VerticalCollage()
{
	delete lhs;
	delete rhs;
	lhs = rhs = nullptr;
	delete[] collageFileName;
	collageFileName = nullptr;
}
