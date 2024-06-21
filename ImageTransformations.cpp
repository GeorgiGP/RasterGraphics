#include "ImageTransformations.h"
#include "FactoryImage.h"

Image * ImageTransformations::getImage() const
{
	return image;
}
const char * ImageTransformations::getImageFileName() const
{
	return image->getName();
}
void ImageTransformations::incrementIndex(unsigned & index)
{
	(++index) %= capacity;
}
void ImageTransformations::decrementIndex(unsigned & index)
{
	(--index) %= capacity;
}
bool ImageTransformations::resize()
{
	if (capacity >= INT_MAX)
	{
		return false;
	}
	Transformation** newTransforms = new Transformation*[capacity *= MULTIPLIER];
	for (size_t i = 0; i < size; i++)
	{
		newTransforms[i] = transformations[get];
		incrementIndex(get);
	}
	delete[] transformations;
	transformations = newTransforms;
	get = 0;
	put = size;
	return true;
}
void ImageTransformations::popLast()
{
	if (isEmpty())
	{
		return;
	}
	decrementIndex(put);
	delete transformations[put];
	transformations[put] = nullptr;
	size--;

	if (isEmpty())
	{
		put = get = 0;
	}
}

bool ImageTransformations::isEmpty() const
{
	return !size;
}
inline void ImageTransformations::popFirst()
{
	if (isEmpty())
	{
		return;
	}

	delete transformations[get];
	transformations[get] = nullptr;
	size--;

	if (isEmpty())
	{
		put = get = 0;
	}
	else
	{
		incrementIndex(get);
	}
}
void ImageTransformations::copyFrom(const ImageTransformations& other)
{
	image = other.image->clone();

	size = other.size;
	capacity = other.capacity;
	get = other.get;
	put = other.put;

	transformations = new Transformation*[capacity];
	unsigned index = get;
	for (size_t i = 0; i < size; i++)
	{
		transformations[index] = other.transformations[index]->clone(image);
		incrementIndex(index);
	}
}
void ImageTransformations::moveFrom(ImageTransformations&& other)
{
	image = other.image;

	transformations = other.transformations;
	size = other.size;
	capacity = other.capacity;
	get = other.get;
	put = other.put;

	other.image = nullptr;
	other.transformations = nullptr;
	other.size = other.capacity = other.get = other.put = 0;
}
void ImageTransformations::free()
{
	delete image;
	image = nullptr;

	while (!isEmpty())
	{
		popLast();
	}
	delete[] transformations;
	transformations = nullptr;

	size = capacity = get = put = 0;
}
ImageTransformations::ImageTransformations(Image* img) 
{
	if (!img)
	{
		throw std::nullptr_t();
	}
	image = img->clone(); 
	transformations = new Transformation*[capacity] {nullptr};
}

ImageTransformations::ImageTransformations(const ImageTransformations & other)
{
	copyFrom(other);
}

ImageTransformations::ImageTransformations(ImageTransformations && other) noexcept
{
	moveFrom(std::move(other));
}

ImageTransformations & ImageTransformations::operator=(const ImageTransformations & other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

ImageTransformations & ImageTransformations::operator=(ImageTransformations && other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

ImageTransformations::~ImageTransformations()
{
	free();
}

void ImageTransformations::undo()
{
	popLast();
}

bool ImageTransformations::addTransformation(Transformation* addTr)
{
	if (size >= capacity && !resize())
	{
		return false;
	}
	transformations[put] = addTr->clone(image);
	incrementIndex(put);
	size++;
	return true;
}

void ImageTransformations::saveAs(const char * withName)
{
	if (!withName)
	{
		throw std::nullptr_t();
	}
	if (!image)
	{
		while (!isEmpty())
		{
			popFirst();
		}
	}
	else
	{
		while (!isEmpty())
		{
			transformations[get]->execute();
			popFirst();
		}
	}
	
	image->deserialize(withName);
}

void ImageTransformations::save()
{
	saveAs(image->getName());
}

void ImageTransformations::printInfo() const
{
	std::cout << "Image: " << image->getName();
	if (isEmpty())
	{
		std::cout << " - has no upcomming transformations." << std::endl;
	}
	else
	{
		std::cout << std::endl << "has pending transformations: ";
		unsigned index = get;
		for (size_t i = 0; i < size - 1; i++) //transformations behave like a stack but execute like a queue, so we know if it has elemen, it starts from the beginning
		{
			transformations[index]->print();
			std::cout << ", ";
			(++index) %= capacity; //incrementingIndex
		}
		transformations[index]->print();
		std::cout << '.' <<  std::endl;
	}
}

