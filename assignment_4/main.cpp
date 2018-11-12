#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iomanip>
#include "utilities.h"
#include "tests.h"
#include "playMastermind.h"


int main() {
	int valg;
	do {
		std::cout << "Velg funksjon: \n"
			<< "0) Avslutt \n"
			<< "1) testCallByvalue() \n" 
			<< "2) swapNumbers() \n"
			<< "3) testTableSorting() \n"
			<< "4) testCStrings() \n" 
			<< "5) Play Mastermind" << std::endl;
		std::cin >> valg;
		switch (valg) {
			case 0: break;
			case 1: testCallByValue();
				break;
			case 2: std::cout << "Gi inn et tall (a): ";
				int a;
				std::cin >> a;
				std::cout << "Gi in et tall til (b): ";
				int b;
				std::cin >> b;
				swapNumbers(&a, &b);
				std::cout << "Swapped:\t" << "a = " << a
					<< "\tb = " << b << std::endl;
				break;
			case 3: testTableSorting();
				break;
			case 4: testCStrings();
				break;
			case 5: playMastermind();
				break;
		}
		system("pause");
		std::cout << "------------------" << std::endl;
	} while (valg != 0);
	return 0;
}