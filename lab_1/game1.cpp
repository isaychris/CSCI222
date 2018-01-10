#include <iostream>
#include <time.h>
#include <iomanip> 
#include <stdlib.h>
#include "card.h"
#include "deck.h"
#include "game1.h"
#include <fstream>

using namespace std;

ofstream csis;

int main() {
	//Chris Banci
	//010031304

	srand((unsigned)time(NULL));

	csis.open("csis1.txt");

	displayHeading();			//displays the header text

	for (int t = 0; t < 10; ++t) { 

		++trial;

		for (int i = 0; i < 10000; ++i) {
			d.shuffle(100);								//shuffles deck 100 times

			for (int i = 0; i < 5; ++i) {
				c[i] = d.getCard();						//gets the card

				cardValue[i] = c[i].getValue();			//sets values to value array
				cardSuit[i] = c[i].getSuit();			//sets suits to suit array
			}

			++hands;

			//check for pairs and flushes
			if (cardValue[0] == cardValue[1] || cardValue[0] == cardValue[2] || cardValue[0] == cardValue[3] || cardValue[0] == cardValue[4] || cardValue[1] == cardValue[2] || cardValue[1] == cardValue[3] || cardValue[1] == cardValue[4] || cardValue[2] == cardValue[3] || cardValue[2] == cardValue[4] || cardValue[3] == cardValue[4]) {
				++pairr;
			}

			if (cardSuit[0] == cardSuit[1] && cardSuit[1] == cardSuit[2] && cardSuit[2] == cardSuit[3] && cardSuit[3] == cardSuit[4]){
				++flushh;
			}

			//returns cards back to deck
			for (int i = 0; i < 5; ++i) {
				d.addCard(c[i]);				//returns cardobject[i] back to deck object.
			}

		}

		//make values into arrays
		trialflush[t] = flushh;
		trialpair[t] = pairr;

		percFlush[t] = ((trialflush[t]) / (10000.00)) * 100;		//flush calculation to percentage
		percPair[t] = ((trialpair[t]) / (10000.00)) * 100;			//pair calculation to percentage

		displayResult(t);					//displays results text

		//resets values
		hands = 0;
		flushh = 0;
		pairr = 0;

	}

	for (int i = 0; i < 10; ++i) {		//avg calculation
		avgFlush += percFlush[i];
		avgPair += percPair[i];
	}

	avgFlush = avgFlush / 10.00;		//avg calculation to percentage
	avgPair = avgPair / 10.00;

	displayAvg();					//displays Avg text

	csis.close();

	return 0;
}


void displayHeading() {
	cout << "//Poker Lab - Part 1 \n" << endl;

	cout << setw(5) << "Trial" << setw(10) << "Hands" << setw(10) << "Pairs"
		<< setw(10) << "Flush" << setw(10) << "% Pairs" << setw(10) << "% Flush" << endl;
	cout << " " << endl;

	csis << "//Poker Lab - Part 1 \n" << endl;

	csis << setw(5) << "Trial" << setw(10) << "Hands" << setw(10) << "Pairs"
		<< setw(10) << "Flush" << setw(10) << "% Pairs" << setw(10) << "% Flush" << endl;
	csis << " " << endl;
}

void displayResult(int t) {
	cout << setw(5) << trial << setw(10) << hands << setw(10) << trialpair[t]
		<< setw(10) << trialflush[t] << setw(10) << fixed << setprecision(2) << percPair[t] << setw(10) << fixed << setprecision(2) << percFlush[t] << endl;

	cout << "----------------------------------------------------------" << endl;

	csis << setw(5) << trial << setw(10) << hands << setw(10) << trialpair[t]
		<< setw(10) << trialflush[t] << setw(10) << fixed << setprecision(2) << percPair[t] << setw(10) << fixed << setprecision(2) << percFlush[t] << endl;

	csis << "----------------------------------------------------------" << endl;
}

void displayAvg(){
	cout << "Average Pairs %: " << fixed << setprecision(2) << avgPair << endl;
	cout << "Average Flush %: " << fixed << setprecision(2) << avgFlush << endl;

	csis << "Average Pairs %: " << fixed << setprecision(2) << avgPair << endl;
	csis << "Average Flush %: " << fixed << setprecision(2) << avgFlush << endl;
}