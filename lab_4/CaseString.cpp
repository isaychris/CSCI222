//CaseString.cpp

#include "CaseString.h"
#include <fstream>

extern ofstream csis;

CaseString::CaseString() : String() {
}

CaseString::CaseString(const CaseString& chr) : String(chr) {
	upper = new char[length + 1];

	for (int i = 0; i < length; i++) {
		upper[i] = toupper(buf[i]);
	}

	upper[length] = '\0';


	lower = new char[length + 1];

	for (int i = 0; i < length; i++) {
		lower[i] = tolower(buf[i]);
	}

	lower[length] = '\0';
}

CaseString::CaseString(const char* chr) : String(chr) {
	upper = new char[length + 1];

	for (int i = 0; i < length; i++) {
		upper[i] = toupper(chr[i]);
	}

	upper[length] = '\0';

	lower = new char[length + 1];

	for (int i = 0; i < length; i++) {
		lower[i] = tolower(chr[i]);
	}

	lower[length] = '\0';
}


void CaseString::print() {
	cout << "\"" << buf << "\"" << "  " << "Length = " << length << "  " << "Lower = " << lower << "  " << "Upper = " << upper << endl;
	csis << "\"" << buf << "\"" << "  " << "Length = " << length << "  " << "Lower = " << lower << "  " << "Upper = " << upper << endl;

}

CaseString& CaseString::operator=(const CaseString& cstrg){
	length = strlen(cstrg.buf);
	strcpy(buf, cstrg.buf);
	upper = cstrg.upper;
	lower = cstrg.lower;

	return *this;
}

CaseString::~CaseString() {
}