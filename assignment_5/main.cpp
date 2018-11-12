#include <iostream>
#include <string>
#include <sstream>
#include "Card.h"
#include "CardDeck.h"
#include "blackjack.h"

int main() {
	Blackjack b;
	char valg = 'N';
	do {
		b.playGame();
		std::cout << "Do you want to play again? (Y/N)" << std::endl;
		std::cin >> valg;
		valg = toupper(valg);
		std::cout << "-------------------------" << std::endl;
	} while (valg != 'N');
	return 0;
}
