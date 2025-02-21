#pragma once
#include <iostream>

class PPMImage;
class PBMImage;
class PGMImage;

class Image
{
private:
	char* fileName = nullptr;

	void copyFrom(const Image& other); 
	void moveFrom(Image&& other); 
	void free();
public:
	
	Image(const char* fileName);
	Image(const Image& other);
	Image(Image&& other) noexcept;

	Image& operator=(const Image& other);
	Image& operator=(Image&& other) noexcept;
	virtual ~Image();

	const char* getName() const;

	void deserialize() const;
	virtual void deserialize(const char* customName) const = 0;
	virtual Image* clone() const = 0;


	virtual Image* horizontalCollage(const Image* rhs, const char* resultFileName) const = 0;
	virtual Image* horizontalCollagePBM(const PBMImage* rhs, const char* resultFileName) const = 0;
	virtual Image* horizontalCollagePGM(const PGMImage* rhs, const char* resultFileName) const = 0;
	virtual Image* horizontalCollagePPM(const PPMImage* rhs, const char* resultFileName) const = 0;

	virtual Image* verticalCollage(const Image* rhs, const char* resultFileName) const = 0;
	virtual Image* verticalCollagePBM(const PBMImage* rhs, const char* resultFileName) const = 0;
	virtual Image* verticalCollagePGM(const PGMImage* rhs, const char* resultFileName) const = 0;
	virtual Image* verticalCollagePPM(const PPMImage* rhs, const char* resultFileName) const = 0;
	
	virtual void grayscale() = 0;
	virtual void rotateLeft() = 0;
	virtual void rotateRight() = 0;
	virtual void negative() = 0;
	virtual void monochrome() = 0;
};
