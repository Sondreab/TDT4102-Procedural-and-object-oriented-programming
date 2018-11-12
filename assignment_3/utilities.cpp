#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>
#include "cannonball.h"
#include "utilities.h"


int randomWithLimits(int min, int max) {
	int tilfeldigTall = min + std::rand() % (max + 1 - min);
	return tilfeldigTall;
}
/*tar inn en øvre og nedre grense (inkludert i intervallet) og returnerer et,
pseudotilfeldig tall i intervallet*/

int modernRandomWithLimits(int min, int max, std::default_random_engine& generator) {
	std::uniform_int_distribution<int> uniform(min, max);
	int randomInteger = uniform(generator);
	return randomInteger;
}
/*tar inn en øvre og en nedre grense(inkludert i intervall),
returnerer tilfeldig heltall i intervallet*/