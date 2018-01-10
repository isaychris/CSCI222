#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "game2.h"
#include <fstream>

using namespace std;

ofstream csis;

int main() {
	//Chris Banci
	//010031304

	srand((unsigned)time(NULL));				//used to generate random.

	csis.open("csis2.txt");

	displayHeading();							//displays the header

	for (int t = 0; t < 10; ++t) {				//loop for 10 trials
		trial++;

		for (int i = 0; i < 10000; ++i) {		// draw 10,000 5 card hands
			hands++;

			d.shuffle(100);						//shuffles deck to start.

			h[i].dealCards(d);					//deals out a hand
		}

		for (int i = 0; i < 10000; ++i) {		//loop to calculate total pairs/flushes
			totalPair[t] += h[i].pair;
			totalFlush[t] += h[i].flush;
			percPair[t] = totalPair[t];
			percFlush[t] = totalFlush[t];
		}

		displayResult(t);						//displays the results

		hands = 0;

		for (int i = 0; i < 10000; ++i) {		//resets pairs/flush to 0 for new trials
			h[i].flush = 0;
			h[i].pair = 0;
		}
	}

	for (int i = 0; i < 10; ++i) {				//calculates the total avg.
		avgPair += totalPair[i];
		avgFlush += totalFlush[i];
	}

	avgPair = (avgPair / 10000) * 10;			//total avg in percent form.
	avgFlush = (avgFlush / 10000) * 10;

	displayAvg();								//displays Averages

	csis.close();
	return 0;
}


void displayHeading() {
	cout << "//Poker Lab - Part 2 \n" << endl;

	cout << setw(5) << "Trial" << setw(10) << "Hands" << setw(10) << "Pairs"
		<< setw(10) << "Flush" << setw(10) << "% Pairs" << setw(10) << "% Flush" << endl;
	cout << " " << endl;

	csis << "//Poker Lab - Part 2 \n" << endl;

	csis << setw(5) << "Trial" << setw(10) << "Hands" << setw(10) << "Pairs"
		<< setw(10) << "Flush" << setw(10) << "% Pairs" << setw(10) << "% Flush" << endl;
	csis << " " << endl;
}

void displayResult(int t){
	cout << setw(5) << trial << setw(10) << hands << setw(10) << totalPair[t]
		<< setw(10) << totalFlush[t] << setw(10) << fixed << setprecision(2) << (percPair[t] / 10000.00) * 100 << setw(10) << (percFlush[t] / 10000.00) * 100 << endl;
	cout << "----------------------------------------------------------" << endl;

	csis << setw(5) << trial << setw(10) << hands << setw(10) << totalPair[t]
		<< setw(10) << totalFlush[t] << setw(10) << fixed << setprecision(2) << (percPair[t] / 10000.00) * 100 << setw(10) << (percFlush[t] / 10000.00) * 100 << endl;
	csis << "----------------------------------------------------------" << endl;
}

void displayAvg(){
	cout << "Average Pairs %: " << fixed << setprecision(2) << avgPair << endl;
	cout << "Average Flush %: " << fixed << setprecision(2) << avgFlush << endl;
	csis << "Average Pairs %: " << fixed << setprecision(2) << avgPair << endl;
	csis << "Average Flush %: " << fixed << setprecision(2) << avgFlush << endl;
}