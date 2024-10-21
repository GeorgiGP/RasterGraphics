#include "../Commands/Transformations/Specific/Grayscale.h"

Grayscale::Grayscale(Image * img) : Transformation(img)
{	}

void Grayscale::execute()
{
	if (!toImage)
	{
		return;
	}
	toImage->grayscale();
}

Transformation * Grayscale::clone(Image * image)
{
	return new Grayscale(image);
}

void Grayscale::print()
{
	std::cout << "grayscale";
}

Grayscale::~Grayscale()
{
}
