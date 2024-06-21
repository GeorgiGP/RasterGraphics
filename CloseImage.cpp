#include "CloseImage.h"

CloseImage::CloseImage(ListOfSessions *& list) : Manage(list)
{
}

void CloseImage::execute()
{
	receiver->closeFirstImage();
}
