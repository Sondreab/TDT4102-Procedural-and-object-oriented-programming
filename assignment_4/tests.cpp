#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iomanip>
#include "utilities.h"
#include "tests.h"
#include "playMastermind.h"

void testCallByValue() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	std::cout << "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations;
	incrementByValueNumTimes(&v0, increment, iterations);
	std::cout << " result: " << v0 << std::endl;
}
/*tester incrementByValueNumTimes()*/

void testTableSorting() {
	int percentages[20];
	randomizeArray(percentages, sizeof(percentages) / sizeof(percentages[0]));
	printArray(percentages, sizeof(percentages) / sizeof(percentages[0]));
	std::cout << "Median: " 
		<< medianOfArray(percentages, sizeof(percentages) / sizeof(percentages[0])) 
		<< std::endl;
	selectionSort(percentages, sizeof(percentages) / sizeof(percentages[0]));
	printArray(percentages, sizeof(percentages) / sizeof(percentages[0]));
	std::cout << "Median: "
		<< medianOfArray(percentages, sizeof(percentages) / sizeof(percentages[0]))
		<< std::endl;
}
/*testfunksjon for array sortering*/

void testCStrings() {
	double totAverage = 0;
	for (int k = 1; k <= 5; k++) {
		std::cout << k << ". aar:" << std::endl;
		char grades[9];
		//randomizeCString(grades, sizeof(grades) / sizeof(grades[0]), 'A', 'E');
		readInputToCString(grades, sizeof(grades) / sizeof(grades[0]), 'A', 'E');
		std::cout << grades << std::endl;
		int gradeCount[6];
		gradeCount[0] =
			countOccurencesOfCharacter(grades, sizeof(grades) / sizeof(grades[0]), 'A');
		gradeCount[1] =
			countOccurencesOfCharacter(grades, sizeof(grades) / sizeof(grades[0]), 'B');
		gradeCount[2] =
			countOccurencesOfCharacter(grades, sizeof(grades) / sizeof(grades[0]), 'C');
		gradeCount[3] =
			countOccurencesOfCharacter(grades, sizeof(grades) / sizeof(grades[0]), 'D');
		gradeCount[4] =
			countOccurencesOfCharacter(grades, sizeof(grades) / sizeof(grades[0]), 'E');
		gradeCount[5] =
			countOccurencesOfCharacter(grades, sizeof(grades) / sizeof(grades[0]), 'F');
		double average = 0;
		int numGrades = 0;
		for (int i = 0; i < 6; i++) {
			average += (i + 1)*gradeCount[i];
		}
		average /= (sizeof(grades) / sizeof(grades[0]) - 1);
		std::cout << "Antall: \t";
		for (int j = 0; j < 6; j++) {
			std::cout << (char)('A' + j) << ": " << gradeCount[j] << "\t";
		}
		std::cout << "\nGjennomsnittskarakter " << k << ". aar:\t" 
			<< (char)('A' + (round(average) - 1))
			<< "\t(" << std::setprecision(2) << average << ")" << std::endl;
		totAverage += round(average);
	}
	totAverage /= 5.0;
	std::cout << "Gjennomsnittskarakter totalt: " 
		<< (char)('A' + (round(totAverage) - 1))
		<< "\t(" << totAverage << ")" << std::endl;
}
/*Testfunksjon for C-strings*/