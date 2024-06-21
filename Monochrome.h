#pragma once
#include "Transformation.h"
#include "Image.h"

class Monochrome : public Transformation
{
public:
	Monochrome() = default;
	Monochrome(Image* img);

	void execute() override;
	Transformation* clone(Image* image) override;
	void print() override;
};