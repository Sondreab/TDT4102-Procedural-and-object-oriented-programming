#pragma once


int randomWithLimits(int min, int max);
/*tar inn en øvre og nedre grense (inkludert i intervallet) og returnerer et,
pseudotilfeldig tall i intervallet*/

int modernRandomWithLimits(int min, int max, std::default_random_engine& generator);
/*tar inn en øvre og en nedre grense(inkludert i intervall),
returnerer tilfeldig heltall i intervallet*/