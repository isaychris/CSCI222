#ifndef _GAME1_H
#define _GAME1_H

#include "card.h"
#include "deck.h"

	//objects
	Deck d;
	Card c[5];

	Card::Value cardValue[5];
	Card::Suit cardSuit[5];

	//functions
	void displayHeading();
	void displayResult(int);
	void displayAvg();

	//variables
	int pairr = 0;
	int flushh = 0;
	int trial = 0;
	int hands = 0;
	int trialpair[10];
	int trialflush[10];
	double percFlush[10];
	double percPair[10];
	double avgFlush = 0.0;
	double avgPair = 0.0;

#endif