//String.h

#ifndef _String_
#define _String_

#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class String {
protected:
	char *buf;		
	int length;

public:
	//default constructors
	String();
	String(const char*);
	String(char);
	String(int);
	String(const String&);
	String(char, int);
	~String();				

	int getLength(); //returns length
	void print();	//prints pointer

	//assigment overloading
	String& operator=(const String&);
	String& operator=(const char*);

	//concatenation overloading
	String& operator+=(const String&);
	friend String operator+(const String&, const String&);
	friend String operator+(const String&, const char*);
	friend String operator+(const char*, const String&);
	friend String operator+(const String&, const char);
	friend String operator+(const char, const String&);

	//unary overloading
	String operator+() const; //converts to uppercase

	//substring function
	String substr(int, int);

	//comparsion overading
	friend int operator>=(const String&, const String&);
	friend int operator==(const String&, const String&);
	friend int operator!=(const String&, const String&);
	friend int operator< (const String&, const String&);
	friend int operator<=(const String&, const String&);
	friend int operator> (const String&, const String&);

	//pointer notation overloading
	friend char* operator+(const String&, int);
	friend char* operator+(int, const String&);

	//increment overloading
	String& operator++();
	String& operator--();
	String& operator++(int);
	String& operator--(int);

	//subscript overloading
	char& operator[](int);

	//cout overload
	friend ostream& operator<<(ostream&, const String&);
};

#endif