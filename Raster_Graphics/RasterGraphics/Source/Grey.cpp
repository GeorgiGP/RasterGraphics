#include "../Sessions/ElementsSession/Image/ColorThemes/Grey.h"

Grey::Grey(unsigned char grey) : grey(grey) {}

void Grey::setColor(unsigned char grey)
{
	this->grey = grey;
}

unsigned char Grey::getShade() const
{
	return grey;
}
