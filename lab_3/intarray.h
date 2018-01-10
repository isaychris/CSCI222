#ifndef _INTARRAY_H
#define _INTARRAY_H

#include "iadrv.h"

using namespace std;

class IntArray {
private:
	string arrayName; 
	int lowIndice; //low indice
	int highIndice; //high indice
	int elements; //number of elements
	int size; //size
	int *dArray; //dynamic array
public:
	//constructors
	IntArray(); 
	IntArray(int); 
	IntArray(int, int);
	
	//set methods
	void setName(string);

	//get methods
	string getName(); //returns name
	int low(); //returns lowIndice
	int high(); //returns high indice
	
	//operator overloading
	friend ostream& operator << (ostream&, IntArray&);
	int& operator[](int); //subscript
	IntArray operator+(IntArray&); //additon
	IntArray operator+=(IntArray&); 
	IntArray& operator=(IntArray&); //asignment
	bool operator==(IntArray&); //comparsion
	bool operator!=(IntArray&); //comparsion
}; 

#endif