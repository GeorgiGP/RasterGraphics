#include "BitSetMatrix.h"

static unsigned getMaxBucketsNumber(unsigned cols)
{
	return cols / (unsigned)BITS_PER_BYTE + !!(cols % (unsigned)BITS_PER_BYTE);
}
void BitSetMatrix::copyFrom(const BitSetMatrix & other)
{
	rows = other.rows;
	cols = other.cols;
	bucketsPerRow = other.bucketsPerRow;

	BitSet = new unsigned char*[rows];
	for (size_t i = 0; i < rows; i++)
	{
		BitSet[i] = new unsigned char[bucketsPerRow];
		for (size_t j = 0; j < bucketsPerRow; j++)
		{
			BitSet[i][j] = other.BitSet[i][j];
		}
	}
}

//unsigned long BitSetMatrix::getCellNumber(unsigned rowIndex, unsigned colIndex) const
//{
//	return cols * rowIndex + colIndex;
//}

unsigned BitSetMatrix::getBucketPos(unsigned colIndex) const
{
	return colIndex / BITS_PER_BYTE;
}

unsigned short BitSetMatrix::getPosition(unsigned colIndex) const
{
	return colIndex % BITS_PER_BYTE;
}

unsigned char BitSetMatrix::getMask(unsigned colIndex) const
{
	return 1 << (BITS_PER_BYTE - 1 - getPosition(colIndex));
}

unsigned BitSetMatrix::getBucketsPerRowCount() const
{
	return bucketsPerRow;
}

unsigned BitSetMatrix::getWidth() const
{
	return cols;
}

unsigned BitSetMatrix::getLen() const
{
	return rows;
}

unsigned char BitSetMatrix::getBucket(unsigned rowIndex, unsigned colIndexBucket) const
{
	return BitSet[rowIndex][colIndexBucket];
}

void BitSetMatrix::setBucket(unsigned rowIndex, unsigned colIndexBucket, unsigned char bucket)
{
	BitSet[rowIndex][colIndexBucket] = bucket;
}

void BitSetMatrix::moveFrom(BitSetMatrix && other)
{
	rows = other.rows;
	cols = other.cols;
	bucketsPerRow = other.bucketsPerRow;
	BitSet = other.BitSet;

	other.rows = other.cols = other.bucketsPerRow = 0;
	other.BitSet = nullptr;

}

void BitSetMatrix::free()
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] BitSet[i];
		BitSet[i] = nullptr;
	}
	delete[] BitSet;
	BitSet = nullptr;
	rows = cols = bucketsPerRow = 0;
}

void BitSetMatrix::setTrueAtPos(unsigned rowIndex, unsigned colIndex)
{
	BitSet[rowIndex][getBucketPos(colIndex)] |= getMask(colIndex);
}

void BitSetMatrix::setFalseAtPos(unsigned rowIndex, unsigned colIndex)
{
	unsigned char full = 255;
	full ^= getMask(colIndex); //excluding 1 bit
	BitSet[rowIndex][getBucketPos(colIndex)] &= full; // to exclude it at place
}

bool BitSetMatrix::getAtPosition(unsigned rowIndex, unsigned colIndex) const
{
	return BitSet[rowIndex][getBucketPos(colIndex)] & getMask(colIndex);
}

BitSetMatrix::BitSetMatrix(unsigned rows, unsigned cols) : rows(rows), cols(cols)
{
	bucketsPerRow = getMaxBucketsNumber(cols);
	BitSet = new unsigned char*[rows];
	for (size_t i = 0; i < rows; i++)
	{
		BitSet[i] = new unsigned char[bucketsPerRow] {};
	}
}
BitSetMatrix::BitSetMatrix(const BitSetMatrix & other)
{
	copyFrom(other);
}

BitSetMatrix::BitSetMatrix(BitSetMatrix && other) noexcept
{
	moveFrom(std::move(other));
}

BitSetMatrix & BitSetMatrix::operator=(const BitSetMatrix & other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

BitSetMatrix & BitSetMatrix::operator=(BitSetMatrix && other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

BitSetMatrix::~BitSetMatrix()
{
	free();
}

