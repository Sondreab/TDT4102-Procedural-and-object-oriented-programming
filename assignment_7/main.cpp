#include <iostream>
#include "dynamicMemoryAllocation.h"
#include "Matrix.h"

int main() {
	Matrix A(2);
	Matrix B(2);
	Matrix C(2);

	A.set(0, 1, 2);
	A.set(1, 0, 3);
	A.set(1, 1, 4);

	B.set(0, 0, 4);
	B.set(0, 1, 3);
	B.set(1, 0, 2);

	C.set(0, 1, 3);
	C.set(1, 0, 1.5);
	C.set(1, 1, 2);


	std::cout << A << std::endl << std::endl;
	std::cout << B << std::endl << std::endl;
	std::cout << C << std::endl << std::endl;

	A += B + C;
	
	std::cout << A << std::endl << std::endl;
	
	return 0;
}