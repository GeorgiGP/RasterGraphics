#include "Monochrome.h"

Monochrome::Monochrome(Image * img) : Transformation(img)
{
}

void Monochrome::execute()
{
	if (!toImage)
	{
		return;
	}
	toImage->monochrome();
}

Transformation * Monochrome::clone(Image * image)
{
	return new Monochrome(image);
}

void Monochrome::print()
{
	std::cout << "monochrome";
}
