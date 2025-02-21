#pragma once
#include <iostream>
template <class T>
class Collection 
{
private:
	static const unsigned short DEFAULT_CAPACITY = 8;
	static const unsigned short MULTIPLIER = 2;

private:
	T** data = nullptr;
	unsigned size = 0;
	unsigned capacity = DEFAULT_CAPACITY;

	unsigned put = 0;
	unsigned get = 0;

	bool resize();
	void incrementIndex(unsigned& index);
	void decrementIndex(unsigned& index);

	void free();
public:
	Collection();

	Collection(const Collection& other) = delete;

	Collection<T>& operator=(const Collection& other) =delete;

	~Collection();

	bool pushBack(T* newElement);
	void popLast();
	void popFirst();
	T* peek() const;

	bool isEmpty() const;
	unsigned getSize() const;
};

template<class T>
inline bool Collection<T>::resize()
{
	if (capacity >= INT_MAX)
	{
		return false;
	}
	T** newData = new T*[capacity *= MULTIPLIER]{nullptr};
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

template<class T>
inline void Collection<T>::incrementIndex(unsigned & index)
{
	(++index) %= capacity;
}

template<class T>
inline void Collection<T>::decrementIndex(unsigned & index)
{
	(--index) %= capacity;
}

template<class T>
inline void Collection<T>::free()
{
	while (!isEmpty())
	{
		popFirst();
	}
	delete[] data;
	data = nullptr;
	size = capacity = put = get = 0;
}

template<class T>
inline Collection<T>::Collection()
{
	data = new T*[DEFAULT_CAPACITY] {nullptr};
}

template<class T>
inline Collection<T>::~Collection()
{
	free();
}

template<class T>
inline bool Collection<T>::pushBack(T* newElement) //steal it
{
	if (size==capacity && !resize())
	{
		return false;
	}
	if (!newElement)
	{
		return false;
	}
	data[put] = newElement;
	incrementIndex(put);
	size++;
	newElement = nullptr;
	return true;
}

template<class T>
inline void Collection<T>::popLast()
{
	if (isEmpty())
	{
		return;
	}
	delete data[put - 1];
	data[put - 1] = nullptr;
	size--;

	if (isEmpty())
	{
		put = get = 0;
	}
	else
	{
		decrementIndex(put);
	}
	
	
}

template<class T>
inline void Collection<T>::popFirst()
{
	if (isEmpty())
	{
		return;
	}
	
	delete data[get];
	data[get] = nullptr;
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

template<class T>
inline T * Collection<T>::peek() const
{
	if (isEmpty())
	{
		return nullptr;
	}
	return data[get];
	
}

template<class T>
inline bool Collection<T>::isEmpty() const
{
	return !size;
}

template<class T>
inline unsigned Collection<T>::getSize() const
{
	return size;
}
