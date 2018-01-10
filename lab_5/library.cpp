// library.cpp

#include <fstream>

#include "holding.h"
#include "library.h"

using namespace std;
ofstream csis;

int main()
{
	//Chris Banci
	//010031304

	Holding** HoldingObjects = new Holding*[5]; //creates 5 array pointers to holding objects

	csis.open("csis.txt");

	cout << "Enter holdings to be stored in a list: " << endl << endl;
	csis << "Enter holdings to be stored in a list: " << endl << endl;

	for (int i = 0; i < 5; i++)
	{
		HoldingObjects[i] = libraryFunct(); //library function called and returns pHolding to array object.
	}

	cout << endl << "Here are the holdings: " << endl << endl;
	csis << endl << "Here are the holdings: " << endl << endl;

	for (int i = 0; i < 5; i++)
	{
		HoldingObjects[i]->print();	//virtual printing for holding array object.
	}

	csis.close();

	delete [] HoldingObjects; //deallocate memory
	return 0;
}

Holding * libraryFunct()
{ //function that creates a new holding and returns book or recording
	Holding * pHolding = nullptr;

	char holding_title[SIZE];
	int holding_num;

	char option;

	tryagain: //jump to label
	cout << "Enter B for book, R for recording: ";
	cin >> option; 	cin.ignore();
	csis << "Enter B for book, R for recording: " << option << endl;

	//.................case switch.................//
	switch (option) 
	{
	default:
		cout << "[Error] Invalid option. Try again." << endl;
		goto tryagain;
		break;

	case 'B': case 'b':		//book case
		char book_author[SIZE];

		cout << "Enter book title: ";
		cin.getline(holding_title, SIZE);
		csis << "Enter book title: " << holding_title << endl;

		cout << "Enter book author: ";
		cin.getline(book_author, SIZE);
		csis << "Enter book author: " << book_author << endl;

		cout << "Enter call number: ";
		cin >> holding_num;
		csis << "Enter call number: " << holding_num << endl;

		pHolding = new Book(holding_title, book_author, holding_num); //pointer holds book.

		return pHolding;
		break;

	case 'R': case 'r':		//recording case
		char rec_performer[SIZE];
		char rec_format;

		cout << "Enter recording title: ";
		cin.getline(holding_title, SIZE);
		csis << "Enter recording title: " << holding_title << endl;

		cout << "Enter performer: ";
		cin.getline(rec_performer, SIZE);
		csis << "Enter performer: " << rec_performer << endl;

		cout << "Enter format: (M)P3, (W)AV, (A)IFF: ";
		cin >> rec_format; cin.ignore();
		csis << "Enter format: (M)P3, (W)AV, (A)IFF: " << rec_format << endl;

		cout << "Enter call number: ";
		cin >> holding_num;
		csis << "Enter call number: " << holding_num << endl;

		pHolding = new Recording(holding_title, rec_format, rec_performer, holding_num);  //pointer holds recording

		return pHolding;
		break;
	}

	return pHolding; //pointer returns as either a book or recording
}
