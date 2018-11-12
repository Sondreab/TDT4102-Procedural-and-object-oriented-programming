#include <iostream>
#include <fstream>
#include "utilities.h"
#include "CourseCatalog.h"


void CourseCatalog::addCourse() {
	std::string key;
	std::string name;
	std::string name2;
	std::cout << "Please enter the course key for the course you want to add: ";
	std::cin >> key;
	std::cin.ignore();
	if (courses.find(key) == courses.end()) {
		std::cout << "Please enter the name/description of the course: ";
		std::cin >> name;
		std::cin.ignore();
		std::getline(std::cin, name2);
		courses[key] = name+name2;
		std::cout << "Added the course " + key + " " + name + " to the catalog!"
			<< std::endl;
	}
	else {
		std::cout << "The course " + key + " " + name + " is already in the catalog"
			<< std::endl;
		char valg = 'N';
		std::cout << "Do you want to change the course's name? (Y/N)";
		std::cin >> valg;
		if (toupper(valg) == 'Y') {
			std::cout << "Please enter new the name/description of the course: ";
			std::cin >> name;
			std::getline(std::cin, name2);
			courses[key] = name+name2;
			std::cout << "The course was changed to " + key + " " + name +
				" in the catalog." << std::endl;
		}
	}
}

void CourseCatalog::removeCourse() {
	std::string key;
	std::cout << "Please enter the course key for the course you want to add: ";
	std::cin >> key;
	courses.erase(key);
}

void CourseCatalog::writeToFile(std::string filename) {
	std::ofstream toFile;
	std::ifstream fromFile;

	toFile.open(filename);
	fromFile.open(filename);


	if (toFile.fail() || fromFile.fail()) {
		std::cout << "Error opening file!" << std::endl;
		std::exit(1);
	}

	//for (auto iter = this->courses.begin(); iter != this->courses.end(); iter++) {
	//	std::string line;
	//	while (std::getline(fromFile, line))
	//	{
	//		std::stringstream ss(line);
	//		std::string word;
	//		ss >> word;
	//		if (iter->first.compare(word) != 0) {
	//			toFile << iter->first << " - " << iter->second << std::endl;
	//		}
	//	}
	//}

	toFile << *this << std::endl;

}

std::ostream& operator<<(std::ostream& os, const CourseCatalog& rhs) {
	for (auto iter = rhs.courses.begin(); iter != rhs.courses.end(); iter++) {
		os << iter->first << " - " << iter->second << std::endl;
	}
	return os;
}