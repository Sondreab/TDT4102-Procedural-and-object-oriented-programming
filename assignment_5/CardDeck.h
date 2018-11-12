#pragma once

class CardDeck {
private:
	Card cards[52];
	int currentCardIndex = 0;
	
	void swap(int a, int b);
public:
	CardDeck();

	void print();
	void printShort();
	void shuffle();
	Card drawCard();
	
};