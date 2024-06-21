#pragma once
#include "Transformation.h"
#include "Image.h"
class RotateRight : public Transformation
{
public:
	RotateRight() = default;
	RotateRight(Image* img);

	void execute() override;
	Transformation* clone(Image* image) override;
	void print() override;
};

