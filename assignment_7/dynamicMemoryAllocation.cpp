#include <iostream>
#include "dynamicMemoryAllocation.h"


void fillInFibonacciNumbers(int result[], int length) {
	int fn = 0;
	int fm = 1;
	int temp = 0;
	for (int i = 0; i < length; i++) {
		if (i == 0) {
			result[i] = fn;
		}
		else if (i == 1) {
			result[i] = fm;
		}
		else {
			temp = fn + fm;
			result[i] = temp;
			fn = fm;
			fm = temp;
		}
	}
}

void printFibonacciArray(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		std::cout << arr[i];
		if (i == length - 1) {
			std::cout << std::endl;
		}
		else {
			std::cout << ", ";
		}
	}
}

void createFibonacci() {
	int n = 0;
	std::cout << "How many numbers of the Fibonacci sequence do you want to generate? ";
	std::cin >> n;
	int *numbers = new int[n] {};
	fillInFibonacciNumbers(numbers, n);
	printFibonacciArray(numbers, n);

	delete[] numbers;
	numbers = nullptr;
}
