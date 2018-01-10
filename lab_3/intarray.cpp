#include <iostream>
#include <string>
#include <cstdlib> 
#include <fstream>

#include "intarray.h"

using namespace std;

IntArray::IntArray() {
	size = 9;

	operator[](9);
	dArray = new int[size];

	lowIndice = 0;
	highIndice = 9;

	elements = size + 1;
}

IntArray::IntArray(int b) {
	size = b-1;

	operator[](b-1);
	dArray = new int[size];

	lowIndice = 0;
	highIndice = b - 1;

	elements = b;
}

IntArray::IntArray(int a, int b) {
	size = b;

	dArray = new int[size];

	lowIndice = a;
	highIndice = b;

	elements = highIndice - lowIndice + 1;

	if (a > b) { 
		cout << "Run-time Error: Illegal Array Bounds." << endl;
		cout << "Diagonstic: 1st indice cannot be bigger than 2nd indice" << endl;
	}
}

void IntArray::setName(string name){
	arrayName = name;
}

string IntArray::getName(){
	return arrayName;
}

int IntArray::low() {;
	return lowIndice;
}

int IntArray::high() {
	return highIndice;
}

ostream& operator<<(ostream& os, IntArray& a) {
	//displays the array object
	for (int i = a.low(); i <= a.high(); i++)
		os << a.getName() << "[" << i << "] = " << a.dArray[i] << " ";
	return os;
}

int& IntArray::operator[](int k){
	//if the index of the array is bigger than the size of the array. error will be shown.
	if (k > size) {
		cout << "Run-time Error: Illegal Index." << endl;
		cout << "Dignostic: Index cannot be bigger than size" << endl;
	}
	return dArray[k];
}

IntArray& IntArray::operator=(IntArray& b){
	//if elements do not match up, they cannot be assigned to each other. error will be shown.
	if (elements != b.elements) {
		cout << "Runtime error: Length mismatch" << endl;
		cout << "Diagnostic: Unable to assign, lengths do not match up." << endl;
	}

	return *this;
}


IntArray IntArray::operator+(IntArray& b) {
	//object is copied to temp object with its indices. then temp object is added with b object to produce c object.
	IntArray temp; 
	IntArray c;

	c.lowIndice = lowIndice;
	c.highIndice = highIndice;

	for (int i = lowIndice, k = b.lowIndice; k <= b.highIndice; i++, k++) {
		temp.dArray[i] = b.dArray[k];
	}

	for (int i = lowIndice; i <= highIndice; i++)  {
		c.dArray[i] = dArray[i] + temp.dArray[i];
	}

	return c;
}

IntArray IntArray::operator+=(IntArray& letter){
	//letter object is copied to temp object with its indices. then temp object is added to this object.
	IntArray temp; 

	for (int i = lowIndice, k = letter.lowIndice; k <= letter.highIndice; i++, k++) {
		temp.dArray[i] = letter.dArray[k];
	}

	for (int i = lowIndice; i <= highIndice; i++)  {
		dArray[i] = dArray[i] + temp.dArray[i];
	}
	
	return *this;
}

bool IntArray::operator==(IntArray& letter){
	if (elements == letter.elements) {
		return 1; //return true
	}
	else {
		return 0; // return false
	}

	if (size == letter.size) {
		return 1; // return false
	}
	else {
		return 0; // return true
	}
}

bool IntArray::operator!=(IntArray& letter){
	if (elements == letter.elements) {
		return 0; // return false
	}
	else {
		return 1; // return true
	}

	if (size == letter.size) {
		return 0; // return false
	}
	else {
		return 1; // return true
	}
}