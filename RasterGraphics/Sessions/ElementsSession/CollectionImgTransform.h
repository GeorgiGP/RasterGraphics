#pragma once
#include "ImageTransformations.h"

class CollectionImgTransform
{
private:
	static const unsigned short DEFAULT_CAPACITY = 8;
	static const unsigned short MULTIPLIER = 2;

private:
	ImageTransformations** data = nullptr;
	unsigned size = 0;
	unsigned capacity = DEFAULT_CAPACITY;

	unsigned put = 0;
	unsigned get = 0;

	bool resize();
	void incrementIndex(unsigned& index);
	void decrementIndex(unsigned& index);

	void copyFrom(const CollectionImgTransform& other);
	void moveFrom(CollectionImgTransform&& other);
	void free();

public:
	CollectionImgTransform();

	CollectionImgTransform(const CollectionImgTransform& other);
	CollectionImgTransform(CollectionImgTransform&& other) noexcept;

	CollectionImgTransform& operator=(const CollectionImgTransform& other);
	CollectionImgTransform& operator=(CollectionImgTransform&& other) noexcept;

	~CollectionImgTransform();

	bool pushBack(const ImageTransformations& newElement);
	bool pushBack(ImageTransformations&& newElement);
	bool popLast();
	bool popFirst();
	ImageTransformations* peek() const;

	bool isEmpty() const;
};

