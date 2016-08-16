// Powerball.cpp

//Author: iSayChris
//Program: Simulates the powerball lottery.
//Date: 1/13/16

#include <stdlib.h>
#include <time.h> 
#include <iostream>

using namespace std;

int match1;
int match2;
int match3;
int match4;
int match5;
int match6;

int winning[5];
int special_winning;
int ticket[5];
int special_ticket;

int ticketCounter;
int matchCounter;
int ticketamount;

const int whiteball_MAX = 10;
const int powerball_MAX = 5;

int whiteball[whiteball_MAX];
int powerball[powerball_MAX];

void fillArrayBalls();
void shuffleBalls();
void generateWinningNumbers();
void checkNumbers();
void totalMatches();
void generateTickets(int);

int main() {
	srand(time(NULL));

	fillArrayBalls();
	generateWinningNumbers();
	shuffleBalls();

	cout << "// Powerball lottery" << endl;
	cout << "// Match all 6 numbers and win 1.5 Billion dollars!" << endl << endl;

	cout << "Winning numbers: " << winning[0] << " " << winning[1] << " " << winning[2] << " " << winning[3] << " " << winning[4] << " PWR " << winning[5] << endl;
	cout << "--------------------------------------" << endl;


	cout << "How many tickets would you like to buy: ";
	cin >> ticketamount;
	cout << endl;

	generateTickets(ticketamount);

	cout << "1 match: " << match1 << endl;
	cout << "2 matches: " << match2 << endl;
	cout << "3 matches: " << match3 << endl;
	cout << "4 matches: " << match4 << endl;
	cout << "5 matches: " << match5 << endl;
	cout << "6 matches: " << match6 << endl;

	return 0;
}

void generateWinningNumbers() { //generates the winning numbers.

	shuffleBalls();

	for (int i = 0; i < 5; i++) {
		winning[i] = whiteball[i];
	}
	special_winning = powerball[0];
}

void fillArrayBalls() { //fills whiteball and powerball arrays with numbers.
	for (int i = 0; i < whiteball_MAX; i++) {     
		whiteball[i] = i+1;
	}
	for (int i = 0; i < powerball_MAX; i++) {     
		powerball[i] = i+1;
	}
}

void shuffleBalls() { //shuffles the whiteballs and balls.

	for (int i = 0; i < whiteball_MAX; i++) {    
		int temp = whiteball[i];
		int randomIndex = rand() % whiteball_MAX;

		whiteball[i] = whiteball[randomIndex];
		whiteball[randomIndex] = temp;
	}

	for (int i = 0; i < powerball_MAX; i++) {   
		int temp = powerball[i];
		int randomIndex = rand() % powerball_MAX;

		powerball[i] = powerball[randomIndex];
		powerball[randomIndex] = temp;
	}
}

void generateTickets(int ticketamount) {
	for (int i = 0; i < ticketamount; i++) {
		shuffleBalls();
		matchCounter = 0;

		for (int i = 0; i < 5; i++) {
			ticket[i] = whiteball[i];

		}
		special_ticket = powerball[0];
		checkNumbers();
		totalMatches();
	}
}

void checkNumbers() {	//checks if any numbers match.
	for (int i = 0; i < 5; i++) {
		if (ticket[i] == winning[0]) {
			matchCounter++;
		}
		else if (ticket[i] == winning[1]) {
			matchCounter++;
		}
		else if (ticket[i] == winning[2]) {
			matchCounter++;
		}
		else if (ticket[i] == winning[3]) {
			matchCounter++;
		}
		else if (ticket[i] == winning[4]) {
			matchCounter++;
		}
	}

	if (special_ticket == special_winning) {
		matchCounter++;
	}
}

void totalMatches() {
	if (matchCounter == 1) {
		match1++;
	}

	else if (matchCounter == 5) {
		match5++;
	}
	else if (matchCounter == 2) {
		match2++;
	}
	else if (matchCounter == 3) {
		match3++;
	}
	else if (matchCounter == 4) {
		match4++;
	}
	else if (matchCounter == 6) {
		match6++;
	}
}