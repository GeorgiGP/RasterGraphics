#include "../Factories/FactoryImage.h"
#include <fstream>
namespace
{
	const unsigned short MAX_BUFF_LEN = 1024;
}

Image* factoryImage(const char * fileNameImage)
{
	if (!fileNameImage)
	{
		throw std::nullptr_t();
	}

	std::ifstream ifs(fileNameImage, std::ios::binary);
	if (!ifs.is_open())
	{
		return nullptr;
	} 
	char buff[MAX_BUFF_LEN];
	ifs >> buff;
	if (!strcmp(buff, "P4"))
	{
		return factoryPBMImage(ifs, fileNameImage);
	}
	else if (!strcmp(buff, "P5"))
	{
		return factoryPGMImage(ifs, fileNameImage);
	}
	else if (!strcmp(buff, "P6"))
	{
		return factoryPPMImage(ifs, fileNameImage);
	}
	return nullptr;

}

PBMImage* factoryPBMImage(std::ifstream& ifs, const char* fileNameImage)
{
	if (!fileNameImage)
	{
		throw std::nullptr_t();
	}
	unsigned width, len;
	ifs >> width >> len;
	ifs.ignore();

	PBMImage* result = new PBMImage(fileNameImage, width, len);
	for (size_t i = 0; i < len; i++)
	{
		for (size_t j = 0; j < result->pixels.getBucketsPerRowCount(); j++)
		{
			unsigned char bucket;
			ifs.read(reinterpret_cast<char*>(&bucket), sizeof(bucket));
			result->pixels.setBucket(i, j, bucket);
		}
		
	}
	ifs.close();
	return result;

}

PGMImage* factoryPGMImage(std::ifstream& ifs, const char* fileNameImage)
{
	if (!fileNameImage)
	{
		throw std::nullptr_t();
	}
	unsigned width, len;
	unsigned capColor;
	ifs >> width >> len >> capColor;
	ifs.ignore();

	PGMImage* result = new PGMImage(fileNameImage, width, len, capColor);
	for (size_t i = 0; i < len; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			Grey g;
			ifs.read(reinterpret_cast<char*>(&g), sizeof(g));
			if (!result->validatePixelCap(g))
			{
				delete result;
				throw std::logic_error("File is not valid, cap doesn't match the pixels values!");
			}
			result->manageAtPosition(i, j) = std::move(g);
		}
	}
	ifs.close();
	return result;
}

PPMImage* factoryPPMImage(std::ifstream& ifs, const char* fileNameImage)
{
	if (!fileNameImage)
	{
		throw std::nullptr_t();
	}
	unsigned width, len;
	unsigned capColor;
	ifs >> width >> len >> capColor;
	ifs.ignore();

	PPMImage* result = new PPMImage(fileNameImage, width, len, capColor);
	for (size_t i = 0; i < len; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			RGB rgb;
			ifs.read(reinterpret_cast<char*>(&rgb), sizeof(rgb));
			if (!result->validatePixelCap(rgb))
			{
				delete result;
				throw std::logic_error("File is not valid, cap doesn't match the pixels values!");
			}
			result->manageAtPosition(i, j) = std::move(rgb);
		}
	}
	ifs.close();
	return result;
}