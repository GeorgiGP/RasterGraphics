#pragma once
#include "Transformation.h"
#include "Image.h"

class Grayscale : public Transformation
{
public:
	Grayscale() = default;
	Grayscale(Image* img);

	void execute() override;
	Transformation* clone(Image* image) override;
	void print() override;

	~Grayscale();
};

