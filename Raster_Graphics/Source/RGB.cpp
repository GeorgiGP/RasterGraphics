#include "../Sessions/ElementsSession/Image/ColorThemes/RGB.h"

RGB::RGB(unsigned char red, unsigned char green, unsigned char blue)
{
	setColor(red, green, blue);
}

void RGB::setRed(unsigned char red)
{
	this->red = red;
}

void RGB::setGreen(unsigned char green)
{
	this->green = green;
}

void RGB::setBlue(unsigned char blue)
{
	this->blue = blue;
}

void RGB::setColor(unsigned char red, unsigned char green, unsigned char blue)
{
	setRed(red);
	setGreen(green);
	setBlue(blue);
}

unsigned char RGB::getRed() const
{
	return red;
}

unsigned char RGB::getGreen() const
{
	return green;
}

unsigned char RGB::getBlue() const
{
	return blue;
}
