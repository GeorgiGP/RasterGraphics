#include "Session.h"

unsigned Session::id = 0;

unsigned Session::incrementId() const
{
	return ++id;
}

Session::Session()
{
	currentId = incrementId();
}

unsigned Session::getLastId()
{
	return id;
}

void Session::addImage(Image * img)
{
	if (!img)
	{
		return;
	}
	CollectionImgTransform result = images;
	while (!result.isEmpty())
	{
		if (!strcmp( result.peek()->getImageFileName(), img->getName() ))
		{
			throw std::logic_error("Can't add one image twice in one session!");
		}
		result.popFirst();
	}
	ImageTransformations iTr(img);
	images.pushBack(iTr);
}

void Session::addTransformation(Transformation * addTr)
{
	CollectionImgTransform result;
	while (!images.isEmpty())
	{
		images.peek()->addTransformation(addTr);
		
		result.pushBack(std::move(*images.peek()));
		images.popFirst();
	}
	images = std::move(result);
}

void Session::closeFirstImage()
{
	if (images.isEmpty())
	{
		throw std::logic_error("No images in current session!");
	}
	images.popFirst();
}

void Session::saveAsFirstImage(const char* withName)
{
	if (!withName)
	{
		throw std::nullptr_t();
	}
	if (images.isEmpty())
	{
		throw std::logic_error("No images in current session!");
	}
	images.peek()->saveAs(withName);
	closeFirstImage();
}

Image * Session::findImage(const char * withName) const //creating new Image!
{
	if (!withName)
	{
		throw std::nullptr_t();
	}
	CollectionImgTransform result = images;
	while (!result.isEmpty())
	{
		if (!strcmp(result.peek()->getImageFileName(), withName))
		{
			return result.peek()->getImage()->clone();
		}
		result.popFirst();
	}
	return nullptr;
	
}

void Session::save()
{
	CollectionImgTransform result;
	while (!images.isEmpty())
	{
		images.peek()->save();
		result.pushBack(std::move(*images.peek()));
		images.popFirst();
	}
	images = std::move(result);
}

void Session::undo()
{
	CollectionImgTransform result;
	while (!images.isEmpty())
	{
		images.peek()->undo();
		result.pushBack(std::move(*images.peek()));
		images.popFirst();
	}
	images = std::move(result);
}

void Session::sessionInfo() const
{
	std::cout << std::endl << "Current session info is:" << std::endl;
	CollectionImgTransform result = images;
	while (!result.isEmpty())
	{
		std::cout << std::endl;
		result.peek()->printInfo();
		result.popFirst();
	}
	
}
