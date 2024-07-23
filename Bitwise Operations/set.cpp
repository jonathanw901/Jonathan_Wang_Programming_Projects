// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang & Omar Daas

#include "set.h"

Set::Set(int size) :BitArray(){
	BitArray set(0);
	data_ = set;
}

/// Destructor
Set::~Set(){}

void Set::initialize(char* words, int size) {
	data_.initialize(words, size);
}

int Set::getCardinality() const {
	int output(0);
	for (int i = 0;i < data_.length();i++) {
		int test = data_.get(i);
		if (test == 1) { output++; }
	}
	return output;
}

BitArray& Set::getData() {
	return data_;
}

bool Set::setUnion(Set& B) {
	bool output = false;
	if (data_.length() == B.getData().length()) {
		for (int i = 0;i < data_.length();i++) {
			if (B.getData().get(i) == 1 || data_.get(i) == 1) {
				data_.set(i,1);
			}
		}
		output = true;
	}
	return output;
}

bool Set::setIntersection(Set& B) {
	bool output = false;

	if (data_.length() == B.getData().length()) {
		for (int i = 0;i < data_.length();i++) {
			if (B.getData().get(i) == 1 && data_.get(i) == 1) {
				data_.set(i,1);
			}
			else {
				data_.set(i, 0);
			}
		}
		output = true;
	}
	return output;
}