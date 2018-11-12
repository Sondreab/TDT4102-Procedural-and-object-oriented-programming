#pragma once

class Blackjack {
private:
	CardDeck deck;
	int playerHand = 0;
	int dealerHand = 0;
	int playerCardsDrawn = 0;
	int dealerCardsDrawn = 0;
	Card playerCards[11];
	Card dealerCards[11];

	bool isAce(Card* card);
	int getCardValue(Card* card);
	int getPlayerCardValue(Card* card);
	int getDealerCardValue(Card* card, int total);
	bool askPlayerDrawCard();
	void drawInitialCards();
	void playerVictory();
	void dealerVictory();
public:
	void playGame();
};