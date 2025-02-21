#pragma once
#include "../../Sessions/ElementsSession/Image/Image.h"
class Transformation
{
protected:
	Image* toImage;
public:
	Transformation() = default;
	Transformation(Image* img);

	virtual Transformation* clone(Image* image) = 0;
	virtual void execute() = 0;
	virtual void print() = 0;

	virtual ~Transformation();
};

