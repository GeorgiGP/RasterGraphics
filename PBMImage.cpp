#include "PBMImage.h"
#include <fstream>
namespace
{
	const char CODE_PBM[] = "P4";
}

PBMImage::PBMImage(const char * fileName, unsigned width, unsigned len) : Image(fileName), pixels(len, width)
{
}


unsigned PBMImage::getWidth() const
{
	return pixels.getWidth();
}

unsigned PBMImage::getLen() const
{
	return pixels.getLen();
}

void PBMImage::manageAtPosition(unsigned row, unsigned col, bool value)
{
	if (pixels.getAtPosition(row, col) == value)
	{
		return;
	}
	value ? (pixels.setFalseAtPos(row, col)) : (pixels.setTrueAtPos(row, col));
}

//BlackWhite & PBMImage::manageAtPosition(unsigned row, unsigned col)
//{
//	return pixels.manageAtPosition(row, col);
//}
//
//const BlackWhite & PBMImage::getPixel(unsigned row, unsigned col) const
//{
//	return pixels.getPixel(row, col);
//}

void PBMImage::deserialize(const char* customName) const
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

	ofs << CODE_PBM << '\n';
	ofs << getWidth() << ' ' << getLen() << '\n';

	for (size_t i = 0; i < pixels.getLen(); i++)
	{
		for (size_t j = 0; j < pixels.getBucketsPerRowCount(); j++)
		{
			unsigned char bucket = pixels.getBucket(i, j);
			ofs.write(reinterpret_cast<const char*>(&bucket), sizeof(bucket));
		}
	}
	ofs.close();
}

Image * PBMImage::clone() const
{
	return new PBMImage(*this);
}

Image * PBMImage::horizontalCollage(const Image * rhs, const char * resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	return rhs->horizontalCollagePBM(this, resultFileName);
}

Image * PBMImage::horizontalCollagePBM(const PBMImage* rhs, const char* resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	if (this->getLen() != rhs->getLen())
	{
		throw std::logic_error("Sizes of the picture must be matching!");
	}
	unsigned resultWidth = this->getWidth() + rhs->getWidth();
	PBMImage* result = new PBMImage(resultFileName, resultWidth, this->getLen());
	
	for (size_t i = 0; i < getLen(); i++)
	{
		for (size_t j = 0; j < this->getWidth(); j++)
		{
			(this->pixels.getAtPosition(i, j)) ? (result->pixels.setTrueAtPos(i, j)) : (result->pixels.setFalseAtPos(i, j));
			//result->manageAtPosition(i, j) = this->getPixel(i, j);
		}
		for (size_t j = this->getWidth(); j < resultWidth; j++)
		{
			( rhs->pixels.getAtPosition(i, j - this->getWidth()) ) ? (result->pixels.setTrueAtPos(i, j)) : (result->pixels.setFalseAtPos(i, j));
			//result->manageAtPosition(i, j) = rhs->getPixel(i, j - this->getWidth());
		}
	}
	return result;
}

Image * PBMImage::horizontalCollagePGM(const PGMImage * rhs, const char* resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	throw std::logic_error("When making collage the type of files must be matching.");
}

Image * PBMImage::horizontalCollagePPM(const PPMImage * rhs, const char * resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	throw std::logic_error("When making collage the type of files must be matching.");
}

Image * PBMImage::verticalCollage(const Image * rhs, const char * resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	return rhs->verticalCollagePBM(this, resultFileName);
}

Image * PBMImage::verticalCollagePBM(const PBMImage* rhs, const char* resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	if (this->getWidth() != rhs->getWidth())
	{
		throw std::logic_error("Sizes of the picture must be matching!");
	}
	unsigned resultLen = this->getLen() + rhs->getLen();
	PBMImage* result = new PBMImage(resultFileName, this->getWidth(), resultLen);

	for (size_t i = 0; i < this->getLen(); i++)
	{
		for (size_t j = 0; j < this->getWidth(); j++)
		{
			(this->pixels.getAtPosition(i, j)) ? (result->pixels.setTrueAtPos(i, j)) : (result->pixels.setFalseAtPos(i, j));
			//result->manageAtPosition(i, j) = this->getPixel(i, j);
		}
	}
	for (size_t i = this->getLen(); i < resultLen; i++)
	{
		for (size_t j = 0; j < rhs->getWidth(); j++)
		{
			(rhs->pixels.getAtPosition(i - this->getLen(), j)) ? (result->pixels.setTrueAtPos(i, j)) : (result->pixels.setFalseAtPos(i, j));
	
		}
	}
	return result;
}

Image * PBMImage::verticalCollagePGM(const PGMImage * rhs, const char* resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	throw std::logic_error("When making collage the type of files must be matching.");
}

Image * PBMImage::verticalCollagePPM(const PPMImage * rhs, const char * resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	throw std::logic_error("When making collage the type of files must be matching.");
}

void PBMImage::grayscale()
{
	return;
}

void PBMImage::rotateLeft()
{
	unsigned resWidth = getLen();
	unsigned resLen = getWidth();
	BitSetMatrix resPixels(resLen, resWidth); //flipped
	for (size_t i = 0; i < resLen; i++)
	{
		for (size_t j = 0; j < resWidth; j++)
		{
			(this->pixels.getAtPosition(j, resLen - i - 1)) ? (resPixels.setTrueAtPos(i, j)) : (resPixels.setFalseAtPos(i, j));
			//resPixels.manageAtPosition(i, j) = pixels.getPixel(j, resLen - i - 1);
		}
	}
	this->pixels = std::move(resPixels);
}

void PBMImage::rotateRight()
{
	unsigned resWidth = getLen();
	unsigned resLen = getWidth();
	BitSetMatrix resPixels(resLen, resWidth); //flipped
	for (size_t i = 0; i < resLen; i++)
	{
		for (size_t j = 0; j < resWidth; j++)
		{
			(this->pixels.getAtPosition(resWidth - j - 1, i)) ? (resPixels.setTrueAtPos(i, j)) : (resPixels.setFalseAtPos(i, j));
			//resPixels.manageAtPosition(i, j) = pixels.getPixel(resWidth - j - 1, i);
		}
	}
	this->pixels = std::move(resPixels);
}

void PBMImage::negative()
{
	for (size_t i = 0; i < getLen(); i++)
	{
		for (size_t j = 0; j < getWidth(); j++)
		{
			(this->pixels.getAtPosition(i, j)) ? (this->pixels.setFalseAtPos(i, j)) : (this->pixels.setTrueAtPos(i, j));
			//bool flippedColor = getPixel(i, j).isWhiteCheck() ^ 1;
			//manageAtPosition(i, j).setColor(flippedColor);
		}
	}
}

void PBMImage::monochrome()
{
	return;
}
