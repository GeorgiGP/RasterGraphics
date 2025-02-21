#pragma once
#include "../../Image.h"
#include "../PicturePixels.h"
#include "../../ColorThemes/RGB.h"

class PPMImage : public Image
{
private:
	static const unsigned char DEFAULT_CAP = 255;

private:
	PicturePixels<RGB> pixels;
	unsigned capColor = DEFAULT_CAP;

public:
	PPMImage(const char* fileName, unsigned width, unsigned len, unsigned capColor);

	bool validatePixelCap(const RGB& rgb) const;

	unsigned getWidth() const;
	unsigned getLen() const;
	unsigned getCapColor() const;
	RGB& manageAtPosition(unsigned row, unsigned col);
	const RGB& getPixel(unsigned row, unsigned col) const;
	
	void deserialize(const char* customName) const override;
	virtual Image* clone() const override;

	virtual Image* horizontalCollage(const Image* rhs, const char* resultFileName) const override;
	virtual Image* horizontalCollagePBM(const PBMImage* rhs, const char* resultFileName) const override;
	virtual Image* horizontalCollagePGM(const PGMImage* rhs, const char* resultFileName) const override;
	virtual Image* horizontalCollagePPM(const PPMImage* rhs, const char* resultFileName) const override;

	virtual Image* verticalCollage(const Image* rhs, const char* resultFileName) const override;
	virtual Image* verticalCollagePBM(const PBMImage* rhs, const char* resultFileName) const override;
	virtual Image* verticalCollagePGM(const PGMImage* rhs, const char* resultFileName) const override;
	virtual Image* verticalCollagePPM(const PPMImage* rhs, const char* resultFileName) const override;

	virtual void grayscale() override;
	virtual void rotateLeft() override;
	virtual void rotateRight() override;
	virtual void negative() override;
	virtual void monochrome() override;
};

