#include "AddImage.h"

AddImage::AddImage(ListOfSessions *& list, Image * img) : Manage(list) , img(img)
{
}

void AddImage::execute()
{
	if (!img)
	{
		throw std::logic_error("Add valid image!");
	}
	receiver->addImage(img);
}

AddImage::~AddImage()
{
	delete img;
	img = nullptr;
}
