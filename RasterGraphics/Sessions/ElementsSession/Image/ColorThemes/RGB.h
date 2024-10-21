#pragma once
struct RGB
{
private:
	unsigned char red = 0;
	unsigned char green = 0;
	unsigned char blue = 0;

public:
	RGB() = default;
	RGB(unsigned char red, unsigned char green, unsigned char blue);
	
	void setRed(unsigned char red);
	void setGreen(unsigned char green);
	void setBlue(unsigned char blue);
	void setColor(unsigned char red, unsigned char green, unsigned char blue);

	unsigned char getRed() const;
	unsigned char getGreen() const;
	unsigned char getBlue() const;
};

