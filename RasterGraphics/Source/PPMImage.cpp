#include "../Sessions/ElementsSession/Image/ImageFormats/PPM/PPMImage.h"
#include <fstream>

namespace
{
	const char CODE_PPM[] = "P6";
}

template<class T>
static T averageOf3(const T& first, const T& second, const T& third)
{
	return (first / 3 + second / 3 + third / 3);
}
static unsigned char getGreyValue(const RGB& color)
{
	return averageOf3<unsigned char>(color.getRed(), color.getGreen(), color.getBlue());
}
static RGB getGrey(const RGB& color)
{
	unsigned char mid = getGreyValue(color);
	return RGB(mid, mid, mid);
}
PPMImage::PPMImage(const char * fileName, unsigned width, unsigned len, unsigned capColor) : Image(fileName), capColor(capColor), pixels(width, len)
{
}

bool PPMImage::validatePixelCap(const RGB& rgb) const
{
	return (rgb.getRed() <= capColor && rgb.getGreen() <= capColor && rgb.getBlue() <= capColor);
}

unsigned PPMImage::getWidth() const
{
	return pixels.getWidth();
}

unsigned PPMImage::getLen() const
{
	return pixels.getLen();
}

unsigned PPMImage::getCapColor() const
{
	return capColor;
}

RGB& PPMImage::manageAtPosition(unsigned row, unsigned col)
{
	return pixels.manageAtPosition(row, col);
}

const RGB & PPMImage::getPixel(unsigned row, unsigned col) const
{
	return pixels.getPixel(row, col);
}

void PPMImage::deserialize(const char * customName) const
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
	ofs << CODE_PPM << '\n';
	ofs << getWidth() << ' ' << getLen() << '\n';
	ofs << getCapColor() << '\n';

	for (size_t i = 0; i < getLen(); i++)
	{
		for (size_t j = 0; j < getWidth(); j++)
		{
			unsigned char red = getPixel(i, j).getRed();
			ofs.write(reinterpret_cast<const char*>(&red), sizeof(red));

			unsigned char green = getPixel(i, j).getGreen();
			ofs.write(reinterpret_cast<const char*>(&green), sizeof(green));

			unsigned char blue = getPixel(i, j).getBlue();
			ofs.write(reinterpret_cast<const char*>(&blue), sizeof(blue));
		}
	}
	ofs.close();
}

Image * PPMImage::clone() const
{
	return new PPMImage(*this);
}

Image * PPMImage::horizontalCollage(const Image * rhs, const char * resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	return rhs->horizontalCollagePPM(this, resultFileName);
}

Image * PPMImage::horizontalCollagePBM(const PBMImage * rhs, const char * resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	throw std::logic_error("When making collage the type of files must be matching.");
}

Image * PPMImage::horizontalCollagePGM(const PGMImage * rhs, const char * resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	throw std::logic_error("When making collage the type of files must be matching.");
}

Image * PPMImage::horizontalCollagePPM(const PPMImage * rhs, const char * resultFileName) const
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
	PPMImage* result = new PPMImage(resultFileName, resultWidth, this->getLen(), this->getCapColor());

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

Image * PPMImage::verticalCollage(const Image * rhs, const char * resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	return rhs->verticalCollagePPM(this, resultFileName);
}

Image * PPMImage::verticalCollagePBM(const PBMImage* rhs, const char* resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	throw std::logic_error("When making collage the type of files must be matching.");

}

Image * PPMImage::verticalCollagePGM(const PGMImage * rhs, const char* resultFileName) const
{
	if (!resultFileName)
	{
		throw std::nullptr_t();
	}
	throw std::logic_error("When making collage the type of files must be matching.");

}

Image * PPMImage::verticalCollagePPM(const PPMImage * rhs, const char * resultFileName) const
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
	PPMImage* result = new PPMImage(resultFileName, this->getWidth(), resultLen, this->getCapColor());

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

void PPMImage::grayscale()
{
	for (size_t i = 0; i < getLen(); i++)
	{
		for (size_t j = 0; j < getWidth(); j++)
		{
			pixels.manageAtPosition(i, j) = getGrey(pixels.getPixel(i, j));
		}
	}
}

void PPMImage::rotateLeft()
{
	unsigned resWidth = getLen();
	unsigned resLen = getWidth();
	PicturePixels<RGB> resPixels(resWidth, resLen); //flipped
	for (size_t i = 0; i < resLen; i++)
	{
		for (size_t j = 0; j < resWidth; j++)
		{
			resPixels.manageAtPosition(i, j) = pixels.getPixel(j, resLen - i - 1);
		}
	}
	pixels = std::move(resPixels);
}

void PPMImage::rotateRight()
{
	unsigned resWidth = getLen();
	unsigned resLen = getWidth();
	PicturePixels<RGB> resPixels(resWidth, resLen); //flipped
	for (size_t i = 0; i < resLen; i++)
	{
		for (size_t j = 0; j < resWidth; j++)
		{
			resPixels.manageAtPosition(i, j) = pixels.getPixel(resWidth - j - 1, i);
		}
	}
	pixels = std::move(resPixels);
}

void PPMImage::negative()
{
	for (size_t i = 0; i < getLen(); i++)
	{
		for (size_t j = 0; j < getWidth(); j++)
		{
			unsigned char flippedRed = capColor - getPixel(i, j).getRed();
			unsigned char flippedGreen = capColor - getPixel(i, j).getGreen();
			unsigned char flippedBlue = capColor - getPixel(i, j).getBlue();
			manageAtPosition(i, j).setColor(flippedRed, flippedGreen, flippedBlue);
		}
	}
}

void PPMImage::monochrome()
{
	for (size_t i = 0; i < getLen(); i++)
	{
		for (size_t j = 0; j < getWidth(); j++)
		{
			if (getGreyValue(pixels.getPixel(i, j)) <= capColor/2)
			{
				pixels.manageAtPosition(i, j).setColor(0,0,0);
			}
			else
			{
				pixels.manageAtPosition(i, j).setColor(capColor, capColor, capColor);
			}			
		}
	}
}
