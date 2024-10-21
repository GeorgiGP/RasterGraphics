#pragma once
#include "Image/Image.h"
#include "../../Collection.hpp"
#include "../../Commands/Transformations/Transformation.h"

class ImageTransformations
{
private:
	static const unsigned short DEFAULT_CAPACITY = 8;
	static const unsigned short MULTIPLIER = 2;

private:
	Image* image = nullptr;

	Transformation** transformations = nullptr;
	unsigned capacity = DEFAULT_CAPACITY;
	unsigned size = 0;
	unsigned get = 0;
	unsigned put = 0;

	void incrementIndex(unsigned& index);
	void decrementIndex(unsigned& index);
	bool resize();
	void popLast();
	bool isEmpty() const;
	void popFirst();

	void copyFrom(const ImageTransformations& other);
	void moveFrom(ImageTransformations&& other);
	void free();
public:
	ImageTransformations(Image* img);
	ImageTransformations(const ImageTransformations& other);
	ImageTransformations(ImageTransformations&& other) noexcept;

	ImageTransformations& operator=(const ImageTransformations& other);
	ImageTransformations& operator=(ImageTransformations&& other) noexcept;
	~ImageTransformations();

	Image* getImage() const;
	const char* getImageFileName() const;
	
	void undo();
	bool addTransformation(Transformation* addTr);
	void saveAs(const char* withName);
	void save();

	void printInfo() const;

	
};

