// book.h

#ifndef _BOOK_H
#define _BOOK_H

#include "holding.h"

class Book : public Holding //inherits holding class
{
private:
	char* author;

public:
	Book(const Book&); 
	Book(char*, char*, int);

	virtual ~Book();
	virtual void print();

};

#endif