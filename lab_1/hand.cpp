#include "card.h"
#include "deck.h"
#include "hand.h"

using namespace std;

void Hand::dealCards(Deck& d) {
	for (int i = 0; i < 5; i++) { // deals out 5 cards
		c[i] = d.getCard(); //returns a card to card object array

		cardValue[i] = c[i].getValue(); //returns value to cardvalue array
		cardSuit[i] = c[i].getSuit(); //returns suit to cardsyut array

	}

	checkHand();

	for (int i = 0; i < 5; i++) { //adds card objects back to deck
		d.addCard(c[i]);
	}
}


void Hand::checkHand() {
	//finding aleast a pair
	if (cardValue[0] == cardValue[1] || cardValue[1] == cardValue[2] || cardValue[2] == cardValue[3] || cardValue[3] == cardValue[4] || cardValue[4] == cardValue[0] || cardValue[0] == cardValue[2] || cardValue[0] == cardValue[3] || cardValue[1] == cardValue[3] || cardValue[1] == cardValue[4] || cardValue[2] == cardValue[4]) {
		++pair;
	}

	//finding a flush
	if (cardSuit[0] == cardSuit[1] && cardSuit[1] == cardSuit[2] && cardSuit[2] == cardSuit[3] && cardSuit[3] == cardSuit[4]){
		++flush;
	}
}
