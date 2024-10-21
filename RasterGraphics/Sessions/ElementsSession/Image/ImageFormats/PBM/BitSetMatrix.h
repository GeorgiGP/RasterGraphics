#pragma once
#include <iostream>

namespace
{
	const unsigned short BITS_PER_BYTE = 8;
}

class BitSetMatrix
{

private:

	unsigned char** BitSet = nullptr;
	unsigned bucketsPerRow = 0;

	unsigned rows = 0;
	unsigned cols = 0;
	
	//unsigned long getCellNumber(unsigned rowIndex, unsigned colIndex) const;
	unsigned getBucketPos(unsigned colIndex) const;
	unsigned short getPosition(unsigned colIndex) const;
	unsigned char getMask(unsigned colIndex) const;

	void copyFrom(const BitSetMatrix& other);
	void moveFrom(BitSetMatrix&& other);
	void free();

public:

	BitSetMatrix(unsigned rows, unsigned cols);
	BitSetMatrix(const BitSetMatrix& other);
	BitSetMatrix(BitSetMatrix&& other) noexcept;

	BitSetMatrix& operator=(const BitSetMatrix& other);
	BitSetMatrix& operator=(BitSetMatrix&& other) noexcept;
	~BitSetMatrix();

	unsigned getBucketsPerRowCount() const;
	unsigned getWidth() const;
	unsigned getLen() const;

	unsigned char getBucket(unsigned rowIndex, unsigned colIndexBucket) const;
	void setBucket(unsigned rowIndex, unsigned colIndex, unsigned char colIndexBucket);

	void setTrueAtPos(unsigned rowIndex, unsigned colIndex);
	void setFalseAtPos(unsigned rowIndex, unsigned colIndex);

	bool getAtPosition(unsigned rowIndex, unsigned colIndex) const;
};
