#pragma once
#include <iostream>

template <class T>
class PicturePixels
{
	T** pixels = nullptr;
	unsigned width = 0;
	unsigned len = 0;

	void copyFrom(const PicturePixels& other);
	void moveFrom(PicturePixels&& other);
	void free();

public:
	PicturePixels(unsigned width, unsigned len);
	PicturePixels(const PicturePixels& other);
	PicturePixels(PicturePixels&& other) noexcept;

	PicturePixels<T>& operator=(const PicturePixels& other);
	PicturePixels<T>& operator=(PicturePixels&& other) noexcept;
	~PicturePixels();

	unsigned getWidth() const;
	unsigned getLen() const;

	const T& getPixel(unsigned row, unsigned col) const;
	T& manageAtPosition(unsigned row, unsigned col);

};

template<class T>
inline unsigned PicturePixels<T>::getWidth() const
{
	return width;
}

template<class T>
inline unsigned PicturePixels<T>::getLen() const
{
	return len;
}

template<class T>
inline const T & PicturePixels<T>::getPixel(unsigned row, unsigned col) const
{
	return pixels[row][col];
}

template<class T>
inline T & PicturePixels<T>::manageAtPosition(unsigned row, unsigned col)
{
	return pixels[row][col];
}

template<class T>
inline void PicturePixels<T>::copyFrom(const PicturePixels & other)
{
	len = other.len;
	width = other.width;
	pixels = new T*[len];
	for (size_t i = 0; i < len; i++)
	{
		pixels[i] = new T[width];
	}
	for (size_t i = 0; i < len; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			pixels[i][j] = other.pixels[i][j];
		}
	}
}

template<class T>
inline void PicturePixels<T>::moveFrom(PicturePixels && other)
{
	pixels = other.pixels;
	width = other.width;
	len = other.len;

	other.pixels = nullptr;
	other.len = other.width = 0;
}

template<class T>
inline void PicturePixels<T>::free()
{
	for (size_t i = 0; i < len; i++)
	{
		delete[] pixels[i];
		pixels[i] = nullptr;
	}
	delete[] pixels;
	pixels = nullptr;
	width = len = 0;
}

template<class T>
inline PicturePixels<T>::PicturePixels(unsigned width, unsigned len) : width(width) , len(len)
{
	pixels = new T*[len];
	for (size_t i = 0; i < len; i++)
	{
		pixels[i] = new T[width];
	}
}

template<class T>
inline PicturePixels<T>::PicturePixels(const PicturePixels & other)
{
	copyFrom(other);
}

template<class T>
inline PicturePixels<T>::PicturePixels(PicturePixels && other) noexcept
{
	moveFrom(std::move(other));
}

template<class T>
inline PicturePixels<T> & PicturePixels<T>::operator=(const PicturePixels & other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<class T>
inline PicturePixels<T>& PicturePixels<T>::operator=(PicturePixels && other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<class T>
inline PicturePixels<T>::~PicturePixels()
{
	free();
}
