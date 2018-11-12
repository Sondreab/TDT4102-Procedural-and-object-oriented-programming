#include <iostream>
#include <algorithm>
#include "SimpleSet.h"

SimpleSet::SimpleSet() {
	maxSize = 0;
	currentSize = 0;
}

SimpleSet::~SimpleSet() {
	delete[] data;
	data = nullptr;
}

bool SimpleSet::insert(int value) {
	if (find(value) != -1) {
		return -1;
	}
	if (currentSize >= maxSize) {
		resize(maxSize + 3);
	}
	data[currentSize] = value;
	currentSize++;
	return true;
}

bool SimpleSet::exists(int value) {
	return find(value) != -1;
}

bool SimpleSet::remove(int value) {
	int index = find(value);

	if (index != -1) {
		if (currentSize - 1 != index) {
			data[index] = data[currentSize - 1];
		}
		currentSize--;
		return true;
	}
	else {
		return false;
	}

}

int SimpleSet::find(int value) {
	for (int index = 0; index < currentSize; index++) {
		if (data[index] == value) {
			return index;
		}
	}
	return -1;
}

void SimpleSet::resize(int newSize) {
	int *newdata = new int[newSize];
	for (int i = 0; i < maxSize; i++) {
		newdata[i] = data[i];
	}
	int *temp = data;
	data = newdata;
	if (maxSize > 0) {
		delete temp;
	}
	maxSize = newSize;
}

std::ostream& operator <<(std::ostream &os, const SimpleSet &set) {
	for (int i = 0; i < set.currentSize; i++) {
		os << set.data[i];
		os << "\n";
	}
	return os;
}