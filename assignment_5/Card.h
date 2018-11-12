#pragma once

enum Suit
{
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES
};

enum Rank
{
	TWO = 2,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE
};

struct CardStruct {
	Suit s;
	Rank r;
};

class Card {
private:
	Suit s;
	Rank r;
	bool invalid;
public:
	void initialize(Suit s, Rank r);
	Suit getSuit();
	Rank getRank();
	std::string toString();
	std::string toStringLong();

	Card();
	Card(Suit s, Rank r);
};
 
std::string suitToString(Suit color);

std::string rankToString(Rank value);

std::string toString(CardStruct card);

std::string intToString(int number);

std::string toStringShort(CardStruct card);