#include <iostream>
#include <string>
#include <sstream>
#include "Card.h"
#include "CardDeck.h"
#include "blackjack.h"
#include "utilities.h"

void CardDeck::swap(int a, int b) {
	Card temp = cards[a];
	cards[a] = cards[b];
	cards[b] = temp;
}

CardDeck::CardDeck() {
	int teller = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 2; j <= 14; j++) {
			cards[teller] = Card(static_cast<Suit>(i), static_cast<Rank>(j));
			teller++;
		}
	}
}

void CardDeck::print() {
	for (int i = 0; i < 52; i++) {
		std::cout << rankToString(cards[i].getRank()) + " of "
			+ suitToString(cards[i].getSuit()) << std::endl;
	}

}

void CardDeck::printShort() {
	for (int i = 0; i < 52; i++) {
		std::cout << cards[i].toString() << std::endl;
	}
}

void CardDeck::shuffle() {
	std::random_device seeder;
	std::default_random_engine generator(seeder());
	for (int i = 0; i <= 1000; i++) {
		swap(modernRandomWithLimits(0, 51, generator),
			modernRandomWithLimits(0,51, generator));
	}
}

Card CardDeck::drawCard() {
	Card drawnCard = cards[currentCardIndex];
	currentCardIndex++;
	return drawnCard;
}