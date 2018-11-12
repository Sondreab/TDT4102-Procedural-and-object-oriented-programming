#include <vector>
#include <string>
#include <iostream>
#include "iterator.h"



void replace(std::vector<std::string> &ref, std::string old, std::string replacement) {
	std::vector<std::string>::iterator iter;
	for (iter = ref.begin(); iter != ref.end(); iter++) {
		if (*iter == old) {
			iter = ref.erase(iter);
			iter = ref.insert(iter, replacement);
		}
	}
}

void printWithIterator(std::vector<std::string> &ref) {
	for (std::vector<std::string>::iterator iter = ref.begin();
	iter != ref.end(); iter++) {
		std::cout << *iter << ", ";
	}
	std::cout << std::endl;
}

void reversePrintWithIterator(std::vector<std::string> &ref) {
	for (std::vector<std::string>::reverse_iterator iter = ref.rbegin();
	iter != ref.rend(); iter++) {
		std::cout << *iter << ", ";
	}
	std::cout << std::endl;
}

