#include <iostream>
#include "readAndWriteFiles.h"
#include "CourseCatalog.h"

int main() {
	CourseCatalog Catalog;
	
	
	int runtime = 1;
	while(runtime){
		int funksjon;
		std::cout << "Choose funksjon:" << std::endl;
		std::cout << "0) Quit" << std::endl
			<< "1) writeWordsToFileOnSeparateLines()" << std::endl
			<< "2) readFileAndWriteToNewWithLineNumbers()" << std::endl
			<< "3) letterStatisticsFromFile()" << std::endl
			<< "4) wordStatisticFromFile()" << std::endl
			<< "5) Catalog.addCourse()" << std::endl
			<< "6) Catalog.removeCourse()" << std::endl
			<< "7) Print Catalog" << std::endl
			<< "8) Catalog.writeToFile()" << std::endl;
		std::cin >> funksjon;
		std::cout << "--------------------" << std::endl;
		std::string readFilename;
		std::string writeFilename;
		switch (funksjon) {
		case 0:
			runtime = 0; break;
		case 1:
			std::cout << "Please enter the name of the file you want to write to: ";
			std::cin >> writeFilename;
			writeWordsToFileOnSeparateLines(writeFilename);
			system("Pause");
			break;
		case 2:
			std::cout << "Please enter the name of the file you want to read from: ";
			std::cin >> readFilename;
			std::cout << "Please enter the name of the file you want to write to: ";
			std::cin >> writeFilename;
			readFileAndWriteToNewWithLineNumbers(readFilename, writeFilename);
			system("Pause");
			break;
		case 3:
			std::cout << "Please enter the name of the file you want to read from: ";
			std::cin >> readFilename;
			letterStatisticsFromFile(readFilename);
			system("Pause");
			break;
		case 4:
			std::cout << "Please enter the name of the file you want to read from: ";
			std::cin >> readFilename;
			wordStatisticFromFile(readFilename);
			system("Pause");
			break;
		case 5:
			Catalog.addCourse();
			system("Pause");
			break;
		case 6:
			Catalog.removeCourse();
			system("Pause");
			break;
		case 7:
			std::cout << Catalog << std::endl;
			system("Pause");
			break;
		case 8:
			std::cout << "Please enter the name of the file you want to write to: ";
			std::cin >> writeFilename;
			Catalog.writeToFile(writeFilename);
			system("Pause");
			break;
		}

	return 0;
}