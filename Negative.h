#pragma once
#include "Transformation.h"
#include "Image.h"

class Negative : public Transformation
{
public:
	Negative() = default;
	Negative(Image* img);

	void execute() override;
	Transformation* clone(Image* image) override;
	void print() override;
};
