#pragma once
struct Grey
{
private:
	unsigned char grey = 0;

public:
	Grey() = default;
	Grey(unsigned char grey);
	void setColor(unsigned char grey);

	unsigned char getShade() const;
};

