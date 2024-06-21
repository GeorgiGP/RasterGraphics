#pragma once
#include "Collection.hpp"
#include "ImageTransformations.h"
#include "CollectionImgTransform.h"
class Session
{
	CollectionImgTransform images;
	static unsigned id;
	unsigned currentId = 0;

	unsigned incrementId() const;

public:
	Session();

	static unsigned getLastId();

	void addImage(Image* img);
	void addTransformation(Transformation* addTr);
	void closeFirstImage();
	void saveAsFirstImage(const char* withName);
	Image* findImage(const char * withName) const;
	void save();
	void undo();
	void sessionInfo() const;
};

