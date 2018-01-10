//ReverseString.h

#ifndef _ReverseString_
#define _ReverseString_

#include <iostream>
#include "String.h"

class ReverseString : public String {
private:
	char* rbuf;

public:
	ReverseString();
	ReverseString(const ReverseString&);
	ReverseString(const char*);
	ReverseString& operator=(const ReverseString&);
	ReverseString operator~();
};

#endif