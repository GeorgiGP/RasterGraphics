#include "../Sessions/ElementsSession/Image/Image.h"
#pragma warning(disable: 4996)
void Image::copyFrom(const Image & other)
{
	fileName = new char[strlen(other.fileName) + 1];
	strcpy(fileName, other.fileName);
}
void Image::moveFrom(Image && other)
{
	fileName = other.fileName;
	other.fileName = nullptr;
}
void Image::free()
{
	delete[] fileName;
	fileName = nullptr;
}
Image::Image(const char * fileName)
{
	if (!fileName)
	{
		throw std::nullptr_t();
	}
	this->fileName = new char[strlen(fileName) + 1];
	strcpy(this->fileName, fileName);
}

Image::Image(const Image & other)
{
	copyFrom(other);
}

Image::Image(Image && other) noexcept
{
	moveFrom(std::move(other));
}

Image & Image::operator=(const Image & other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Image & Image::operator=(Image && other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

const char * Image::getName() const
{
	return fileName;
}

void Image::deserialize() const
{
	deserialize(fileName);
}

Image::~Image()
{
	free();
}
