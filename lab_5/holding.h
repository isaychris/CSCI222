// holding.h

#ifndef _HOLDING_H
#define _HOLDING_H

#include <iostream>
using namespace std;

class Holding //abstract base class
{
protected:
	char* title;
	int number;

public:
	Holding(const Holding&); 
	Holding(char*, int);

	virtual ~Holding();
	virtual void print() = 0;
};

#endif