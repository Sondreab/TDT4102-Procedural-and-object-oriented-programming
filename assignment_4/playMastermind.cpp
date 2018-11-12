#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iomanip>
#include "utilities.h"
#include "tests.h"
#include "playMastermind.h"

const int SIZE = 4;
const int LETTERS = 6;
const char START = 'A';

void playMastermind() {

	char code[SIZE + 1];		code[SIZE] = '\0';
	char guess[SIZE + 1];		code[SIZE] = '\0';

	randomizeCString(code, SIZE + 1, START, (char)(START + (LETTERS - 1)));
	std::cout << code << std::endl;

	int characterAndPosition = 0;
	int totCorrChar = 0;
	int characters = 0;

	std::cout << "Velkommen til Mastermind. \nDu skal naa prove aa gjette en streng med "
		<< SIZE << " bokstaver fra " << START << " til og med "
		<< (char)(START + (LETTERS - 1)) << std::endl;

	do {
		characterAndPosition = 0;
		totCorrChar = 0;
		characters = 0;

		readInputToCString(guess, SIZE + 1, START, (char)(START + (LETTERS - 1)));
		std::cout << "Du gjettet: " << guess << std::endl;

		characterAndPosition = checkCharactersAndPosition(code, guess);
		totCorrChar = checkCharacters(code, guess);
		characters = totCorrChar - characterAndPosition;

		if (characters == 1) {
			std::cout << "Du har " << characters
				<< " riktig bokstav." << std::endl;
		}
		else if(characters > 0){
			std::cout << "Du har " << characters
				<< " riktige bokstaver." << std::endl;
		}
		else if (characters == 0) {
		}
		if (characterAndPosition == 1) {
			std::cout << "Du har " << characterAndPosition
				<< " riktig bokstav paa riktig plass." << std::endl;
		}
		else if (characterAndPosition > 0) {
			std::cout << "Du har " << characterAndPosition
				<< " riktige bokstaver paa riktig plass." << std::endl;
		}
		else if (characterAndPosition==0) {
		}
	} while (characterAndPosition != 4);
	std::cout << "Gratulerer! Du gjettet riktig" << std::endl;
}




//Funksjoner

int checkCharactersAndPosition(char arr1[], char arr2[]) {
	int total = 0;
	for (int i = 0; i < SIZE; i++) {
		if (arr1[i] == arr2[i]) {
			total++;
		}
	}
	return total;
}
/*Skal sammenlikne 2 arrays or gi ut hvor mange av elementene
som er identiske på samme plass.*/

int checkCharacters(char code[], char guess[]) {
	int antCode[LETTERS], antGuess[LETTERS], antChars[LETTERS];
	int correctChars = 0;
	for (int i = 0; i < LETTERS; i++) {
		antCode[i] =
			countOccurencesOfCharacter(code, SIZE + 1, (char)(START + i));
		antGuess[i] =
			countOccurencesOfCharacter(guess, SIZE + 1, (char)(START + i));
	}
	for (int j = 0; j < LETTERS; j++) {
		if (antCode[j] <= antGuess[j]) {
			antChars[j] = antCode[j];
		}
		else {
			antChars[j] = antGuess[j];
		}
		correctChars += antChars[j];
	}
	return correctChars;
}
/*Sammenlikner Fasit og gjett, og returnerer antall riktige bokstaver*/