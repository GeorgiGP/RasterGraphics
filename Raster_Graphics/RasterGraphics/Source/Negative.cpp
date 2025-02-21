#include "../Commands/Transformations/Specific/Negative.h"

Negative::Negative(Image * img) : Transformation(img)
{
}

void Negative::execute()
{
	if (!toImage)
	{
		return;
	}
	toImage->negative();
}

Transformation * Negative::clone(Image * image)
{
	return new Negative(image);
}

void Negative::print()
{
	std::cout << "negative";
}
