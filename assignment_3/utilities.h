#pragma once


int randomWithLimits(int min, int max);
/*tar inn en �vre og nedre grense (inkludert i intervallet) og returnerer et,
pseudotilfeldig tall i intervallet*/

int modernRandomWithLimits(int min, int max, std::default_random_engine& generator);
/*tar inn en �vre og en nedre grense(inkludert i intervall),
returnerer tilfeldig heltall i intervallet*/