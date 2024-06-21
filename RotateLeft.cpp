#include "RotateLeft.h"

RotateLeft::RotateLeft(Image * img) : Transformation(img)
{
}

void RotateLeft::execute()
{
	if (!toImage)
	{
		return;
	}
	toImage->rotateLeft();
}

Transformation * RotateLeft::clone(Image * image)
{
	return new RotateLeft(image);
}

void RotateLeft::print()
{
	std::cout << "rotate left";
}
