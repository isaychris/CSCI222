#ifndef _HAND_H
#define _HAND_H

#include "card.h"
#include "deck.h"

class Hand {
public:
	void dealCards(Deck&);
	void checkHand();
	void print();

	Card::Value cardValue[5];
	Card::Suit cardSuit[5];
	int pair = 0;
	int flush = 0;

private:
	Card c[5];
};

#endif
