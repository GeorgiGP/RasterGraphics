#pragma once
#include "../Sessions/ElementsSession/Image/Image.h"
#include "../Sessions/ElementsSession/Image/ImageFormats/PBM/PBMImage.h"
#include "../Sessions/ElementsSession/Image/ImageFormats/PGM/PGMImage.h"
#include "../Sessions/ElementsSession/Image/ImageFormats/PPM/PPMImage.h"

Image* factoryImage(const char* fileNameImage);

PBMImage* factoryPBMImage(std::ifstream& ifs, const char* fileNameImage);

PGMImage* factoryPGMImage(std::ifstream& ifs, const char* fileNameImage);

PPMImage* factoryPPMImage(std::ifstream& ifs, const char* fileNameImage);

