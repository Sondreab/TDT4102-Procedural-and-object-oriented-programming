#include <iostream>
#include <string>
#include <sstream>
#include "Card.h"
#include "CardDeck.h"
#include "blackjack.h"

std::string suitToString(Suit s) {
	switch (s) {
	case CLUBS:
		return "Clubs";
		break;
	case DIAMONDS:
		return "Diamonds";
		break;
	case HEARTS:
		return "Hearts";
		break;
	case SPADES:
		return "Spades";
		break;
	}
}

std::string rankToString(Rank r) {
	switch (r) {
	case TWO:
		return "Two";
		break;
	case THREE:
		return "Three";
		break;
	case FOUR:
		return "Four";
		break;
	case FIVE:
		return "Five";
		break;
	case SIX:
		return "Six";
		break;
	case SEVEN:
		return "Seven";
		break;
	case EIGHT:
		return "Eight";
		break;
	case NINE:
		return "Nine";
		break;
	case TEN:
		return "Ten";
		break;
	case JACK:
		return "Jack";
		break;
	case QUEEN:
		return "Queen";
		break;
	case KING:
		return "King";
		break;
	case ACE:
		return "Ace";
		break;
	}
}

std::string toString(CardStruct card) {
	return rankToString(card.r) + " of " + suitToString(card.s);
}

std::string intToString(int number) {
	std::stringstream ss;
	ss << number;
	return ss.str();
}

std::string toStringShort(CardStruct card) {
	std::string rankString;
	switch (card.s) {
	case CLUBS:
		rankString = "C";
		break;
	case DIAMONDS:
		rankString = "D";
		break;
	case HEARTS:
		rankString = "H";
		break;
	case SPADES:
		rankString = "S";
		break;
	}
	std::string suitString = intToString(card.r);

	return rankString + suitString;
}

void Card::initialize(Suit s, Rank r) {
	invalid = false;
	this->s = s;
	this->r = r;
}

Suit Card::getSuit() {
	return s;
}

Rank Card::getRank() {
	return r;
}

std::string Card::toString() {
	std::string suitString;
	switch (invalid) {
	case true:
		return "Invalid card";
	case false:
		switch (s) {
		case CLUBS:
			suitString = "C";
			break;
		case DIAMONDS:
			suitString = "D";
			break;
		case HEARTS:
			suitString = "H";
			break;
		case SPADES:
			suitString = "S";
			break;
		}
		return suitString + intToString(r);
	}
}

std::string Card::toStringLong() {
	return rankToString(r) + " of " + suitToString(s);
}

Card::Card() {
	invalid = true;
}

Card::Card(Suit s, Rank r) {
	initialize(s, r);
}
