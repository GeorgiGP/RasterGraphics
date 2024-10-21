#pragma once
#include "../../Image.h"
#include "BitSetMatrix.h"

class PBMImage : public Image
{
private:

	BitSetMatrix pixels;
public:
	PBMImage(const char * fileName, unsigned width, unsigned len);

	unsigned getWidth() const;
	unsigned getLen() const;
	void manageAtPosition(unsigned row, unsigned col, bool value);
	//const BlackWhite& getPixel(unsigned row, unsigned col) const;*/

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

	friend PBMImage* factoryPBMImage(std::ifstream& ifs, const char* fileNameImage);
};

