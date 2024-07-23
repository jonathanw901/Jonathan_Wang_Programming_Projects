// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang & Omar Daas

#include "bitarray.h"
          
//
// void print()
//

// Default Constructor
BitArray::BitArray(int size) : LENGTH(size), data_(nullptr)
{
	
}

// Copy Constructor
BitArray::BitArray(const BitArray & array) : LENGTH(array.LENGTH), BYTES(array.BYTES), data_(nullptr)
{
	if (!data_)
	{
		data_ = new char[BYTES];

		// Deep Copy
		for (int i=0; i < BYTES; i++)
		{
			data_[i] = array.data_[i];
		}
	}
}

// Destructor
BitArray::~BitArray()
{
	if (data_) 
	{
		delete [] data_;
	}
}

// set int position
bool BitArray::set(int position, int bit)
{
	bool output = false;
	//ensures bit is valid
	if (bit == 0 || bit == 1) {
		//check if position is within array
		if (position <= LENGTH) {
			//set bit
			if (bit == 0) {
				data_[position / BIT_IN_BYTE] &= ~(1 << ( (position % BIT_IN_BYTE)));
			}
			else {
				data_[position / BIT_IN_BYTE] |= (1 << ( (position % BIT_IN_BYTE)));
			}
			output = true;
		}
	}
	return output;
}

// get int positiion
bool BitArray::get(int position) const
{
	std::bitset<BIT_IN_BYTE> bits = data_[position / BIT_IN_BYTE];
	bool output = bits[position % 8];
    return output;
}

void BitArray::initialize(char * word, int size)
{
	if (data_)
	{
		delete [] data_;
	}
	
	LENGTH = size * BIT_IN_BYTE;
	BYTES = size;
	data_ = new char[BYTES];

	for (int i=0; i < size; i++)
	{
		data_[i] = word[i];
	}
}

void BitArray::print()
{	
	std::cout <<"|";
	
	for (int i=0; i < BYTES; i++)
	{
		std::bitset<BIT_IN_BYTE> bits = data_[i];
		std::cout << bits << "|";
	}
	
	std::cout << std::endl;	
}

char BitArray::get8(int position) const
{
	return data_[position];
}

void BitArray::clear()
{
	std::bitset<BIT_IN_BYTE> bits;

	for (int i = 0; i < BYTES*BIT_IN_BYTE; i++)
	{
		data_[i] = 0;
	}
}

bool BitArray::flip(int position) {
	bool output = false;

	//check if position is within array
	if (position <= LENGTH) {
		//flip 
		data_[position / BIT_IN_BYTE] ^= (1 << (7 - (position%BIT_IN_BYTE)));

		output = true;
	}

	return output;
}

void BitArray::complement() {
	for (int i = 0;i < BYTES;i++) {
		data_[i] = ~data_[i];
	}
}

void BitArray::set8(char c, int index) {
	std::bitset<BIT_IN_BYTE> bits = c;
	for (int i = 0;i < 8;i++) {
		set(index * 8, bits[i]);
	}
}