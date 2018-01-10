//CaseString.h

#ifndef _CaseString_
#define _CaseString_

#include <iostream>
#include "String.h"

class CaseString : public String {
protected:
	char* upper;
	char* lower;

public:
	CaseString();
	CaseString(const CaseString&);
	CaseString(const char*);
	CaseString& operator=(const CaseString&);
	~CaseString();
	void print();

};

#endif