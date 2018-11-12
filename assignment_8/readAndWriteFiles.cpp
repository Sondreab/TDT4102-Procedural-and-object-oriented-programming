#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include "readAndWriteFiles.h"

void writeWordsToFileOnSeparateLines(std::string filename) {
	std::ofstream toFile;

	toFile.open(filename);

	if (toFile.fail()) {
		std::cout << "Error opening file!" << std::endl;
		std::exit(1);
	}

	std::string writeWord;
	do {
		std::cout << "Input word: ";
		std::cin >> writeWord;
		toFile << writeWord << std::endl;
	} while (writeWord.compare("exit") != 0);

	toFile.close();	
}

void readFileAndWriteToNewWithLineNumbers(std::string readFilename, std::string writeFilename) {
	std::ofstream toFile;
	std::ifstream fromFile;

	fromFile.open(readFilename);
	toFile.open(writeFilename);
	
	if (fromFile.fail()) {
		std::cout << "Error opening read-file!" << std::endl;
		std::exit(1);
	}
	if (toFile.fail()) {
		std::cout << "Error opening write-file!" << std::endl;
		std::exit(1);
	}

	int lineCounter = 1;
	while (!fromFile.eof())	{
		std::string extractedString;
		std::getline(fromFile, extractedString);
		toFile << lineCounter << "\t" << extractedString << std::endl;
		lineCounter++;
	}

	fromFile.close();
	toFile.close();
}

void letterStatisticsFromFile(std::string filename) {
	std::ifstream fromFile;

	fromFile.open(filename);

	if (fromFile.fail()) {
		std::cout << "Error opening read-file!" << std::endl;
		std::exit(1);
	}
	int const LETTERS = 26;
	
	int charStatistics[LETTERS] = {0};
	char letter;
	int totalLetters = 0;
	while (fromFile>>letter) {
		letter = tolower(letter);
		if (letter >= 'a' && letter <= 'z') {
			charStatistics[letter - 'a']++;
			totalLetters++;
		}
	}

	fromFile.close();

	std::cout << "Character statistics:" << std::endl;
	std::cout << "Total numbers of characters: " << totalLetters << std::endl;
	
	for (int i = 0; i < LETTERS; i++) {
		std::cout << (char)('a' + i) << ": " << charStatistics[i] << "\t";
		if ((i+1) % 6 == 0) {
			std::cout << std::endl;
		}
	}

	std::cout << std::endl;
}


void wordStatisticFromFile(std::string filename) {
	std::ifstream fromFile;
	fromFile.open(filename);

	if (fromFile.fail()) {
		std::cout << "Error opening read-file!" << std::endl;
		std::exit(1);
	}

	int numLines = 0;
	int numWords = 0;
	std::string longestWord;
	int charsLongestWord = 0;
	std::string line;
	std::map<std::string, int> numEachWord;
	while (std::getline(fromFile, line)) 
	{
		std::stringstream ss(line);
		std::string word;
		while (ss >> word)
		{
			std::string cleanWord = "";
			int i;
			for (i = 0; i < word.length(); i++) {
				if (isalpha(word[i])) {
					cleanWord += tolower(word[i]);
				}
			}
			if (i > charsLongestWord) {
				charsLongestWord = i;
				longestWord = cleanWord;
			}
			else if (i == charsLongestWord) {
				longestWord += ", " + cleanWord;
			}
			numEachWord[cleanWord]++;
			numWords++;
		}
		numLines++;
	}

	std::cout << "Text statistics:" << std::endl;
	std::cout << "Longest word: " << longestWord << std::endl;
	std::cout << "Letters in longest word: " << charsLongestWord << std::endl;
	std::cout << "Number of words: " << numWords << std::endl;
	std::cout << "Number of lines: " << numLines << std::endl;
	for (std::map<std::string, int>::const_iterator iter = numEachWord.begin();
		iter != numEachWord.end(); iter++)
	{
		std::cout << iter->first << ": " << iter->second << std::endl;
	}
}