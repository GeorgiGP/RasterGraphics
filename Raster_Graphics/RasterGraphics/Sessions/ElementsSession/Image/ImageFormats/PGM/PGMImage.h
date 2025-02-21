#pragma once
#include "../../Image.h"
#include "../PicturePixels.h"
#include "../../ColorThemes/Grey.h"

class PGMImage : public Image
{
private:
	static const unsigned char DEFAULT_CAP = 255;

private:
	PicturePixels<Grey> pixels;
	unsigned capColor = DEFAULT_CAP;

public: 
	PGMImage(const char* fileName, unsigned width, unsigned len, unsigned capColor);

	bool validatePixelCap(const Grey& g) const;

	unsigned getWidth() const;
	unsigned getLen() const;
	unsigned getCapColor() const;
	Grey& manageAtPosition(unsigned row, unsigned col);
	const Grey& getPixel(unsigned row, unsigned col) const;

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

