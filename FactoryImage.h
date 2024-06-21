#pragma once
#include "Image.h"
#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"

Image* factoryImage(const char* fileNameImage);

PBMImage* factoryPBMImage(std::ifstream& ifs, const char* fileNameImage);

PGMImage* factoryPGMImage(std::ifstream& ifs, const char* fileNameImage);

PPMImage* factoryPPMImage(std::ifstream& ifs, const char* fileNameImage);

