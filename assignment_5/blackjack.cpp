#include <iostream>
#include <string>
#include <sstream>
#include "utilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "blackjack.h"

//bool operator == (Rank r1, Rank r2) {
//	return(rankToString(r1) == rankToString(r2));
//}

bool Blackjack::isAce(Card* card) {
	switch (card->getRank()) {
	case 14:
		return true;
	default:
		return false;
	}
}

int Blackjack::getCardValue(Card* card) {
	if (isAce(card)) {
		return -1;
	}else if (card->getRank() >= 10) {
		return 10;
	}
	else {
		return card->getRank();
	}
}

int Blackjack::getPlayerCardValue(Card* card) {
	if (getCardValue(card) == -1) {
		int valg = 0;
		do {
			std::cout << "Do you want your " + card->toStringLong() + " to be 1 or 11?";
			std::cin >> valg;
			if (valg != 1 && valg != 11) {
				std::cout << "Invalid value!" << std::endl;
			}
		} while (valg != 1 && valg != 11);
		return valg;
	}
	else {
		return getCardValue(card);
	}
}

int Blackjack::getDealerCardValue(Card* card, int total) {
	if (isAce(card) && total + 11 <= 21) {
		return 11;
	}
	else if (isAce(card) && total + 11 > 21) {
		return 1;
	}
	else {
		return getCardValue(card);
	}
}

bool Blackjack::askPlayerDrawCard() {
	char valg;
	do {
		std::cout << "\nDo you want another card? (Y/N): ";
		std::cin >> valg;
		valg = toupper(valg);
		if (valg == 'Y') {
			return true;
		}
		else if (valg == 'N') {
			return false;
		}
		else {
			std::cout << "Invalid choice!" << std::endl;
		}
	} while (valg != 'Y' && valg != 'N');
}

void Blackjack::drawInitialCards() {
	playerCards[0] = deck.drawCard();
	playerCards[1] = deck.drawCard();
	playerCardsDrawn = 2;
	std::cout << "Player hand (" + intToString(playerCardsDrawn) + "):" 
		+ "\n\t" + playerCards[0].toStringLong()
		+ "\n\t" + playerCards[1].toStringLong() << std::endl;
	playerHand = getPlayerCardValue(playerCards) + getPlayerCardValue(playerCards + 1);
	std::cout << "Player's total value: " + intToString(playerHand) << std::endl;
	dealerCards[0] = deck.drawCard();
	dealerCards[1] = deck.drawCard();
	dealerCardsDrawn = 2;
	dealerHand += getDealerCardValue(dealerCards, 0);
	std::cout << "\nDealer hand (" + intToString(dealerCardsDrawn) + "):" 
		+ "\n\t" + dealerCards[0].toStringLong() << std::endl;
	std::cout << "Dealer's value: " + intToString(dealerHand) << std::endl;
	dealerHand += getDealerCardValue(dealerCards + 1, dealerHand);
}

void Blackjack::playerVictory() {
	if (dealerHand > 21) {
		std::cout << "-------------------------" << std::endl;
		std::cout << "Congratulations, you won! The dealer's total cardvalue exceeded 21"
			<< std::endl;
	}
	else if (((playerCards[0].getRank() == ACE
			&& playerCards[1].getRank() == KING)
		|| (playerCards[0].getRank() == KING
			&& playerCards[1].getRank() == ACE))
		&& (playerHand == 21)) {
		std::cout << "-------------------------" << std::endl;
		std::cout << "Congratulations, you won! You have BLACKJACK!" << std::endl;
	}
	else {
		std::cout << "-------------------------" << std::endl;
		std::cout << "Congratulations, you won! You beat the dealer's value!" 
			<< std::endl;
	}

	std::cout << "\nDealer's hand:" << std::endl;
	for (int i = 0; i < dealerCardsDrawn; i++) {
		std::cout << "\t" + dealerCards[i].toStringLong() << std::endl;
	}
	std::cout << "Dealer's value: " + intToString(dealerHand) + "\n" << std::endl;
	std::cout << "Player's hand:" << std::endl;
	for (int i = 0; i < playerCardsDrawn; i++) {
		std::cout << "\t" + playerCards[i].toStringLong() << std::endl;
	}
	std::cout << "Player's value: " + intToString(playerHand) + "\n" << std::endl;
}

void Blackjack::dealerVictory() {
	if (playerHand > 21) {
		std::cout << "-------------------------" << std::endl;
		std::cout << "Too bad, you Lost! Your total cardvalue exceeded 21" << std::endl;
	}
	else if (dealerHand == playerHand) {
		std::cout << "-------------------------" << std::endl;
		std::cout << "Too bad, you Lost! You didn't beat the dealer's hand" << std::endl;
	}
	else {
		std::cout << "-------------------------" << std::endl;
		std::cout << "Too bad, you Lost! The dealer beat you!" << std::endl;
	}

	std::cout << "\nDealer's hand:" << std::endl;
	for (int i = 0; i < dealerCardsDrawn; i++) {
		std::cout << "\t" + dealerCards[i].toStringLong() << std::endl;
	}
	std::cout << "Dealer's value: " + intToString(dealerHand) + "\n" << std::endl;
	std::cout << "Player's hand:" << std::endl;
	for (int i = 0; i < playerCardsDrawn; i++) {
		std::cout << "\t" + playerCards[i].toStringLong() << std::endl;
	}
	std::cout << "Player's value: " + intToString(playerHand) + "\n" << std::endl;
}

void Blackjack::playGame() {
	std::cout << "\t-- Welcome to Blackjack! -- \n" << std::endl;
	playerHand = 0;
	playerCardsDrawn = 0;
	dealerHand = 0;
	dealerCardsDrawn = 0;
	deck.shuffle();
	drawInitialCards();

	//Ask player if he wants to draw
	while (askPlayerDrawCard()) {
		playerCards[playerCardsDrawn] = deck.drawCard();
		playerHand += getPlayerCardValue(playerCards + playerCardsDrawn);
		playerCardsDrawn++;
		std::cout << "\nPlayer's hand:" << std::endl;
		for (int i = 0; i < playerCardsDrawn; i++) {
			std::cout << "\t" + playerCards[i].toStringLong() << std::endl;
		}
		std::cout << "Player's value: " + intToString(playerHand) + "\n" << std::endl;
		if (playerHand >= 21) {
			break;
		}
	}

	//Check if he's lost due to exceeding 21, if not, Dealer draws untill dealerHand > 16
	if (playerHand > 21) {
		dealerVictory();
	}
	else {
		while (dealerHand < 17) {
			dealerCards[dealerCardsDrawn] = deck.drawCard();
			dealerHand += getDealerCardValue(dealerCards + dealerCardsDrawn, dealerHand);
			dealerCardsDrawn++;
		}
		if (dealerHand > 21) {
			playerVictory();
		}
		else if (dealerHand == playerHand) {
			if (((playerCards[0].getRank() == ACE
				&& playerCards[1].getRank() == KING)
				|| (playerCards[0].getRank() == KING
					&& playerCards[1].getRank() == ACE))
				&& (playerHand == 21)) {
				playerVictory();
			}
			else {
				dealerVictory();
			}
		}
		else if (playerHand > dealerHand) {
			playerVictory();
		}
		else if (dealerHand > playerHand) {
				dealerVictory();
		}
	}
}