// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang & Omar Daas

#include "dictionary.h"

// Constructor
Dictionary::Dictionary():BitArray() {
	BitArray set(0);
	data_ = set;
	int * table = new int[DICTIONARY_SIZE];
	lookupTable_ = table;
}

// Copy Constructor
Dictionary::Dictionary(const Dictionary& dict) {
	
}

// Destructor
Dictionary::~Dictionary() { delete [] lookupTable_; }

void Dictionary::initialize(char* word, int size) {
	data_.initialize(word, size);
	for (int i = 0; i < DICTIONARY_SIZE;i++) {
		std::bitset<BIT_IN_BYTE> bit = i;
		int cardinality(0);
		for (int b(0);b < BIT_IN_BYTE;b++) {
			if (bit[b] == 1) {
				cardinality++;
				
			}
		}
		lookupTable_[i] = cardinality;
	}
}

int Dictionary::rank(int end, int bit) {
	int output(0);
	for (int i(0);i < data_.bytes();i++) {
		if (end / BIT_IN_BYTE >= i) {
			int index = 0;
			index |= data_.get8(i);
			output = output + lookupTable_[index];
		}
		else if((end - (i * BIT_IN_BYTE) )>= 0) {
			char combine;
			combine|= (data_.get8(i));
			combine  &= ~(255 << (end - (i * BIT_IN_BYTE)));
			int index = 0;
			index |= combine;
			output = output + lookupTable_[index];
		}
	}
	//unoptimized
	/*
	for (int i = 0;i < end;i++) {
		int test = data_.get(i);
		if (test == bit) { output++; }
	}
	*/
	return output;
}

int Dictionary::rank_range(int start, int end, int bit) {
	int output(0);
	for (int i = start;i < end;i++) {
		int test = data_.get(i);
		if (test == bit) { output++; }
	}
	return output;
}

int Dictionary::select(int k, int bit) {
	int output(0);
	for (int i = 0;i < data_.length();i++) {
		int test = data_.get(i);
		if (test == bit) { output++; }
		if (output == k) {
			return i;
		}
	}
	return output;
}

int Dictionary::select_range(int start, int end, int k, int bit) {
	int output(0);
	for (int i = start;i < end;i++) {
		int test = data_.get(i);
		if (test == bit) { output++; }
		if (output == k) {
			return i;
		}
	}
	return output;
}

void Dictionary::printLookupTable(std::ostream& output) {
	for (int i(0);i < DICTIONARY_SIZE;i++) {
		std::cout << lookupTable_[i] << "\n";
	}
}