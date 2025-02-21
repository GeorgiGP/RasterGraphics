#pragma once
#include "../Transformation.h"
#include "../../../Sessions/ElementsSession/Image/Image.h"
class RotateLeft : public Transformation
{
public:
	RotateLeft() = default;
	RotateLeft(Image* img);

	void execute() override;
	Transformation* clone(Image* image) override;
	void print() override;
};

