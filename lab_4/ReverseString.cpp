//ReverseString.cpp

#include "ReverseString.h"

ReverseString::ReverseString() : String() {
}

ReverseString::ReverseString(const ReverseString& rev) : String(rev) {
}

ReverseString::ReverseString(const char* chr) : String(chr) {
}

ReverseString& ReverseString::operator=(const ReverseString& rev) {
		length = strlen(rev.buf);
		strcpy(buf, rev.buf);

		return *this;
}

ReverseString ReverseString::operator~() {
	ReverseString rev;
	rev.buf = buf;
	rev.length = length;

	ReverseString reverse;
	int count = 0;

	for (int i = rev.length-1; i >= 0; i--) {
	reverse.buf[count] = rev.buf[i];
	count++;
	}

	reverse.buf[length] = '\0';

	length = strlen(buf);
	reverse.length = length;

	return reverse;
}