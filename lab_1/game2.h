#ifndef _GAME2_H
#define _GAME2_H

#include "card.h"
#include "deck.h"
#include "hand.h"

	//objects
	Hand h[10000]; 
	Deck d;

	//functions
	void displayHeading();
	void displayResult(int);
	void displayAvg();

	//variables
	int trial = 0;
	int hands = 0;
	int totalPair[10];
	int totalFlush[10];
	double percPair[10];
	double percFlush[10];
	double avgPair = 0.0;
	double avgFlush = 0.0;


#endif
