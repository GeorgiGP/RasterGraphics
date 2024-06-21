#include "PGMImage.h"
#include <fstream>

namespace
{
	const char CODE_PGM[] = "P5";
}

PGMImage::PGMImage(const char * fileName, unsigned width, unsigned len, unsigned capColor) : Image(fileName), capColor(capColor), pixels(width, len)
{
}

bool PGMImage::validatePixelCap(const Grey& g) const
{
	return g.getShade() <= capColor;
}

unsigned PGMImage::getWidth() const
{
	return pixels.getWidth();
}

unsigned PGMImage::getLen() const
{
	return pixels.getLen();
}

unsigned PGMImage::getCapColor() const
{
	return capColor;
}

Grey& PGMImage::manageAtPosition(unsigned row, unsigned col)
{
	return pixels.manageAtPosition(row ,col);
}
const Grey & PGMImage::getPixel(unsigned row, unsigned col) const
{
	return pixels.getPixel(row, col);
}
void PGMImage::deserialize(const char * customName) const
{
	if (!customName)
	{
		throw std::nullptr_t();
	}
	std::ofstream ofs(customName, std::ios::binary);
	if (!ofs.is_open())
	{
		throw std::exception("Couldn't save!");
	}
	ofs << CODE_PGM << '\n';
	ofs << pixels.getWidth() << ' ' << getLen() << '\n';
	ofs << capColor << '\n';
	for (size_t i = 0; i < getLen(); i++)
	{
		for (size_t j = 0; j < getWidth(); j++)
		{
			unsigned char color = getPixel(i, j).getShade();
			ofs.write(reinterpret_cast<const char*>(&color), sizeof(color));
		}
	}
	ofs.close();
}

Image * PGMImage::clone() const
{
	return new PGMImage(*this);
}

Image * PGMImage::horizontalCollage(const Image * rhs, const char * resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	return rhs->horizontalCollagePGM(this, resultFileName);
}

Image * PGMImage::horizontalCollagePBM(const PBMImage * rhs, const char * resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	throw std::logic_error("When making collage the type of files must be matching.");
}

Image * PGMImage::horizontalCollagePGM(const PGMImage * rhs, const char * resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	if (this->getLen() != rhs->getLen())
	{
		throw std::logic_error("Sizes of the picture must be matching!");
	}
	if (this->getCapColor() != rhs->getCapColor())
	{
		throw std::logic_error("The images have different color behaviour!");
	}
	unsigned resultWidth = this->getWidth() + rhs->getWidth();
	PGMImage* result = new PGMImage(resultFileName, resultWidth, this->getLen(), this->getCapColor());

	for (size_t i = 0; i < getLen(); i++)
	{
		for (size_t j = 0; j < this->getWidth(); j++)
		{
			result->manageAtPosition(i, j) = this->getPixel(i, j);
		}
		for (size_t j = this->getWidth(); j < resultWidth; j++)
		{
			result->manageAtPosition(i, j) = rhs->getPixel(i, j - this->getWidth());
		}
	}
	return result;
}

Image * PGMImage::horizontalCollagePPM(const PPMImage * rhs, const char * resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	throw std::logic_error("When making collage the type of files must be matching.");
}

Image * PGMImage::verticalCollage(const Image * rhs, const char * resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	return rhs->verticalCollagePGM(this, resultFileName);
}

Image * PGMImage::verticalCollagePBM(const PBMImage* rhs, const char* resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	throw std::logic_error("When making collage the type of files must be matching.");
	
}

Image * PGMImage::verticalCollagePGM(const PGMImage * rhs, const char* resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	if (this->getWidth() != rhs->getWidth())
	{
		throw std::logic_error("Sizes of the picture must be matching!");
	}
	if (this->getCapColor() != rhs->getCapColor())
	{
		throw std::logic_error("The images have different color behaviour!");
	}
	unsigned resultLen = this->getLen() + rhs->getLen();
	PGMImage* result = new PGMImage(resultFileName, this->getWidth(), resultLen, this->getCapColor());

	for (size_t i = 0; i < this->getLen(); i++)
	{
		for (size_t j = 0; j < this->getWidth(); j++)
		{
			result->manageAtPosition(i, j) = this->getPixel(i, j);
		}
	}
	for (size_t i = this->getLen(); i < resultLen; i++)
	{
		for (size_t j = 0; j < rhs->getWidth(); j++)
		{
			result->manageAtPosition(i, j) = rhs->getPixel(i - this->getLen(), j);
		}
	}
	return result;
}

Image * PGMImage::verticalCollagePPM(const PPMImage * rhs, const char * resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	throw std::logic_error("When making collage the type of files must be matching.");
}

void PGMImage::rotateLeft()
{
	unsigned resWidth = getLen();
	unsigned resLen = getWidth();
	PicturePixels<Grey> resPixels(resWidth, resLen); //flipped
	for (size_t i = 0; i < resLen; i++)
	{
		for (size_t j = 0; j < resWidth; j++)
		{
			resPixels.manageAtPosition(i, j) = pixels.getPixel(j, resLen - i - 1);
		}
	}
	pixels = std::move(resPixels);
}

void PGMImage::rotateRight()
{
	unsigned resWidth = getLen();
	unsigned resLen = getWidth();
	PicturePixels<Grey> resPixels(resWidth, resLen); //flipped
	for (size_t i = 0; i < resLen; i++)
	{
		for (size_t j = 0; j < resWidth; j++)
		{
			resPixels.manageAtPosition(i, j) = pixels.getPixel(resWidth - j - 1, i);
		}
	}
	pixels = std::move(resPixels);
}

void PGMImage::negative()
{
	for (size_t i = 0; i < getLen(); i++)
	{
		for (size_t j = 0; j < getWidth(); j++)
		{
			unsigned char flippedColor = capColor - getPixel(i, j).getShade();
			manageAtPosition(i, j).setColor(flippedColor);
		}
	}
}
void PGMImage::grayscale()
{
	return;
}

void PGMImage::monochrome()
{
	for (size_t i = 0; i < getLen(); i++)
	{
		for (size_t j = 0; j < getWidth(); j++)
		{
			unsigned char color = getPixel(i, j).getShade();
			if (color <= capColor/2)
			{
				manageAtPosition(i, j).setColor(0);
			}
			else
			{
				manageAtPosition(i, j).setColor(capColor);
			}
			
		}
	}
}

