#include "RotateRight.h"

RotateRight::RotateRight(Image * img) : Transformation(img)
{
}

void RotateRight::execute()
{
	if (!toImage)
	{
		return;
	}
	toImage->rotateRight();
}

Transformation * RotateRight::clone(Image * image)
{
	return new RotateRight(image);
}

void RotateRight::print()
{
	std::cout << "rotate right";
}
