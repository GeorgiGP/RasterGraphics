#include "../Sessions/ElementsSession/CollectionImgTransform.h"

bool CollectionImgTransform::resize()
{
	if (capacity >= INT_MAX)
	{
		return false;
	}
	ImageTransformations** newData = new ImageTransformations*[capacity *= MULTIPLIER];
	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[get];
		incrementIndex(get);
	}
	delete[] data;
	data = newData;
	get = 0;
	put = size;
}

void CollectionImgTransform::incrementIndex(unsigned & index)
{
	(++index) %= capacity;
}

void CollectionImgTransform::decrementIndex(unsigned & index)
{
	(--index) %= capacity;
}

void CollectionImgTransform::copyFrom(const CollectionImgTransform & other)
{
	put = other.put;
	get = other.get;
	size = other.size;
	capacity = other.capacity;
	data = new ImageTransformations*[capacity];
	unsigned index = get;
	for (size_t i = 0; i < size; i++)
	{
		data[index] = new ImageTransformations(*other.data[index]);
		incrementIndex(index);
	}
}

void CollectionImgTransform::moveFrom(CollectionImgTransform && other)
{
	data = other.data;
	size = other.size;
	capacity = other.capacity;
	put = other.put;
	get = other.get;

	other.data = nullptr;
	other.size = other.capacity = other.put = other.get = 0;
}

void CollectionImgTransform::free()
{
	while (!isEmpty())
	{
		popFirst();
	}
	delete[] data;
	data = nullptr;
	size = capacity = put = get = 0;
}

CollectionImgTransform::CollectionImgTransform()
{
	size = put = get = 0;
	capacity = DEFAULT_CAPACITY;
	data = new ImageTransformations*[capacity] {nullptr};
}

CollectionImgTransform::CollectionImgTransform(const CollectionImgTransform & other)
{
	copyFrom(other);
}

CollectionImgTransform::CollectionImgTransform(CollectionImgTransform && other) noexcept
{
	moveFrom(std::move(other));
}

CollectionImgTransform & CollectionImgTransform::operator=(const CollectionImgTransform & other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

CollectionImgTransform & CollectionImgTransform::operator=(CollectionImgTransform && other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

CollectionImgTransform::~CollectionImgTransform()
{
	free();
}

bool CollectionImgTransform::pushBack(const ImageTransformations& newElement)
{
	if (size == capacity && !resize())
	{
		return false;
	}
	data[put] = new ImageTransformations(newElement);
	incrementIndex(put);
	size++;
	return true;
}

bool CollectionImgTransform::pushBack(ImageTransformations && newElement)
{
	if (size >= capacity && !resize())
	{
		return false;
	}
	data[put] = new ImageTransformations(std::move(newElement));
	incrementIndex(put);
	size++;
	return true;
}

bool CollectionImgTransform::popLast()
{
	if (isEmpty())
	{
		return false;
	}
	decrementIndex(put);
	delete data[put];
	data[put] = nullptr;
	size--;
	if (isEmpty())
	{
		put = get = 0;
	}
	return true;
}

bool CollectionImgTransform::popFirst()
{
	if (isEmpty())
	{
		return false;
	}
	
	delete data[get];
	data[get] = nullptr;
	incrementIndex(get);
	size--;
	if (isEmpty())
	{
		put = get = 0;
	}
	return true;
}

ImageTransformations * CollectionImgTransform::peek() const
{
	return data[get];
}

bool CollectionImgTransform::isEmpty() const
{
	return !size;
}

