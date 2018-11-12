#include <vector>
#include <string>
#include <iostream>
#include <set>

#include "iterator.h"
#include "SimpleSet.h"

int main() {

	//oppg 1
	/*std::vector<std::string> strings;
	strings.push_back("Lorem");
	strings.push_back("Ipsum");
	strings.push_back("Dolor");
	strings.push_back("Sit");
	strings.push_back("Amet");
	strings.push_back("Consectetur");

	printWithIterator(strings);
	reversePrintWithIterator(strings);
	replace(strings, "Lorem", "Latin");
	printWithIterator(strings);
*/ 

	//Oppg 2
	/*std::set<int> s;

	for (int i = 3; i <= 50; i++) {
		s.insert(i);
	}

	for (int j = 2; j <= 50; j++) {
		for (int i = 3; i <= 50; i++) {
			if (i%j == 0 && i != j) {
				s.erase(i);
			}
		}
	}
	

	std::set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		std::cout << *iter << std::endl;
	}*/	
	/*SimpleSet s;
	for (int i = 3; i <= 50; i++) {
		s.insert(i);
	}

	for (int j = 2; j <= 50; j++) {
		for (int i = 3; i <= 50; i++) {
			if (i%j == 0 && i != j) {
				s.remove(i);
			}
		}
	}

	std::cout << s << std::endl;*/


	return 0;
}