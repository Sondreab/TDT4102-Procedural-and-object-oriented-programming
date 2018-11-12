#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iomanip>
#include "utilities.h"


/*Øving 3*/

int randomWithLimits(int min, int max) {
	int tilfeldigTall = min + std::rand() % (max + 1 - min);
	return tilfeldigTall;
}
/*tar inn en øvre og nedre grense (inkludert i intervallet) og returnerer et,
pseudotilfeldig tall i intervallet*/

//int modernRandomWithLimits(int min, int max, std::default_random_engine& generator) {
//	std::uniform_int_distribution<int> uniform(min, max);
//	int randomInteger = uniform(generator);
//	return randomInteger;
//}
/*tar inn en øvre og en nedre grense(inkludert i intervall),
returnerer tilfeldig heltall i intervallet*/

/*Øving 4*/
void incrementByValueNumTimes(int *startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		*startValue += increment;
	}
}
/*incrementerer startValue numTimes ganger or returnerer verdien startvalue har etter
inkrementereringen*/
/*v0 vil være 5 etter inkrementeringen i oppgave a)*/

void swapNumbers(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
/*Tar inn to heltall og swapper dem.
Ja, denne funksjonen burde bruke pekere fordi den skal resultere i 2 "returverdier",
men en funksjon kan bare returnere én verdi.*/

void printArray(int arr[], int length) {
	std::cout << "Array:\t" << "{" << arr[0];
	for (int i = 1; i < length; i++)
	{
		std::cout << ", " << arr[i];
	}
	std::cout << "}" << std::endl;
}
/*printer en array av hvilken som helst lengde*/

//void randomizeArray(int arr[], int length) {
//	std::random_device seeder;
//	std::default_random_engine generator(seeder());
//	for (int i = 0; i < length; i++) {
//		arr[i] = modernRandomWithLimits(0, 100, generator);
//	}
//}
/*Tar inn et array og lengden, og fyller arrayet med tilfeldige verdier [0-100]*/

void insertionSort(int arr[], int length) {
	for (int i = 1; i < length; i++) {
		int j = i;
		while (j > 0 && arr[j - 1]> arr[j]) {
			swapNumbers(&arr[j], &arr[j - 1]);
			j--;
		}
	}
}
/*Sorterer arr[] med insertionsort.
Sammenlikner to og to elementer og bytter plass på dem hvis det første
er større enn det andre. Repeterer helt til listen er sortert.*/

void selectionSort(int arr[], int length) {
	for (int j = 0; j < length-1; j++) {
		int indexMin = j;
		for (int i = j + 1; i < length; i++) {
			if (arr[i] < arr[indexMin]) {
				indexMin = i;
			}
		}
		if (indexMin != j) {
			swapNumbers(arr + j, arr + indexMin);
		}
	}
}
/*Sorterer arr[] med selection sort.
Går gjennom hele arrayet, finner minste verdi og plasserer elementet først,
går dermed gjennom alle bortsett fra det første, finner det minste og
plasserer det på neste plass, osv.*/

double medianOfArray(int arr[], int length) {
	double median;
	if (length % 2 == 0) {
		median = (arr[(length / 2)-1] + arr[(length / 2)]) / 2;
	}
	else {
		median = arr[length / 2];
	}
	return median;
}
/*Tar inn array og lengde og returnerer medianen (midterste element).
Tar høyde for om det er odde- eller partall antall elementer i arrayet*/

//void randomizeCString(char arr[], int length, char min, char max) {
//	std::random_device seeder;
//	std::default_random_engine generator(seeder());
//	for (int i = 0; i < length - 1; i++) {
//		arr[i] = (char)modernRandomWithLimits(min, max, generator);
//	}
//	arr[length - 1] = '\0';
//}
/*Tar inn en c-streng og fyller arrayet med tilfeldige bokstaver*/


//Sier det er 3 elementer i arrayet...
//void readInputToCString(char arr[], char min, char max) {
	/*std::cout << "Vennligst gi input til de " << sizeof(arr) / sizeof(arr[0]) - 1
		<< " elementene i listen.\n" << "Elementene ma vaere mellom "
		<< min << " og " << max << std::endl;
	char input;
	for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])) - 1; i++) {
		do {
			std::cout << i + 1 << ": ";
			std::cin >> input;
			if (toupper(input) < min || toupper(input) > max) {
				std::cout << input << " er ikke mellom " << min << " og " << max
					<< ". Vennligst gi en ny input." << std::endl;
			}
		} while (toupper(input) < min || toupper(input) > max);
		arr[i] = input;
	}
	arr[(sizeof(arr) / sizeof(arr[0])) - 1] = '\0';
}
Tar inn en c-sting og ber bruker om å fylle den ut.
Bruker skal bes om ny verdi om tegnet er utenfor [min, max]*/

//substitutt for funksjonen over
void readInputToCString(char arr[], int length, char min, char max) {
	std::cout << "Vennligst gi " << length - 1
		<< " elementer mellom " << min << " og " << max << std::endl;
	char input;
	for (int i = 0; i < length - 1; i++) {
		do {
			std::cin >> input;
			if (toupper(input) < min || toupper(input) > max) {
				std::cout << input << " er ikke mellom " << min << " og " << max
					<< ". Vennligst gi en ny input." << std::endl;
			}
		} while (toupper(input) < min || toupper(input) > max);
		arr[i] = toupper(input);
	}
	arr[length - 1] = '\0';
}

int countOccurencesOfCharacter(char arr[], int length, char tegn) {
	int occ = 0;
	for (int i = 0; i < length; i++) {
		if (toupper(arr[i]) == toupper(tegn)) {
			occ++;
		}
	}
	return occ;
}
/*Tar inn en c-streng, lengden til denne og et tegn funksjonen skal
returnere antall forekomster av.*/