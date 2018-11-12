#include <iostream>
#include "utilities.h"
#include "Matrix2x2.h"
#include "Vector2.h"

int main() {

	Matrix2x2 ABCD;
	Vector2 PQ;
	Vector2 XY;

	char valg = 'N';
	do {
		std::cout << "We're gonna solve the equations:\n\n"
			<< "\t I: \t ax + by = p \n"
			<< "\tII: \t cx + dy = q \n\n"
			<< "for x and y. \n\n"
			<< "Please give inputs for a, b, c, d, p and q:" << std::endl;
		double inputs[6] = { 0.0 };
		for (int i = 0; i < 2; i++) {
			std::cout << (char)('a' + i) << ": ";
			std::cin >> inputs[i];
			ABCD.set(0, i, inputs[i]);
		}
		for (int i = 0; i < 2; i++) {
			std::cout << (char)('c' + i) << ": ";
			std::cin >> inputs[2 + i];
			ABCD.set(1, i, inputs[2 + i]);
		}
		for (int i = 0; i < 2; i++) {
			std::cout << (char)('p' + i) << ": ";
			std::cin >> inputs[4 + i];
			PQ.set(i, inputs[4 + i]);
		}
		std::cout << "--------------------------" << std::endl;
		if (ABCD.det() == 0.0) {
			std::cout << "The equations\n\n"
			<< "\t I: \t " << doubleToString(ABCD.get(0, 0))
				<< "x + " << doubleToString(ABCD.get(0, 1))
				<< "y = " << doubleToString(PQ.get(0))
				<< "\n\tII: \t " << doubleToString(ABCD.get(1, 0))
				<< "x + " << doubleToString(ABCD.get(1, 1))
				<< "y = " << doubleToString(PQ.get(1)) << "\n" << std::endl;
			std::cout << "have no solutions." << std::endl;
		}
		else {
			XY = ABCD.inv()*PQ;
			std::cout << "The equations\n\n"
				<< "\t I: \t " << doubleToString(ABCD.get(0,0))
				<< "x + " << doubleToString(ABCD.get(0, 1))
				<< "y = " << doubleToString(PQ.get(0))
				<< "\tII: \t " << doubleToString(ABCD.get(1, 0))
				<< "x + " << doubleToString(ABCD.get(1, 1))
				<< "y = " << doubleToString(PQ.get(1)) << "\n" << std::endl;
			std::cout << "have the solutions: \n"
				<< "x = " << XY.get(0) << "\n"
				<< "y = " << XY.get(1) << std::endl;
		}
		std::cout << "--------------------------" << std::endl;
		std::cout << "Do you want to calculate another solution?"
			<< "(Y/N)" << std::endl;
		std::cin >> valg;
		valg = toupper(valg);
	} while (valg != 'N');
	


	return 0;
}
