// String.cpp

#include "String.h"
#include <fstream>
#include <string>

extern ofstream csis;

String::String() {
	length = 0;						
	buf = new char[length + 1];			
	buf[0] = '\0';				
}

String::String(const char* strg) {
	length = int(strlen(strg));
	buf = new char[length + 1];

	for (int i = 0; i < length; i++) {
		buf[i] = strg[i];
	}

	buf[length] = '\0';
}

String::String(char chr) {
	length = 1;
	buf = new char[length];
	buf[0] = chr;
	buf[length] = '\0';
}

String::String(int integer) {

	if (integer < 0) {
		integer = 0;
	}

	buf = new char[integer];
	buf[0] = '\0';
	length = strlen(buf);
}

String::String(const String& strg) {
	length = strg.length;
	buf = new char[length];
	strcpy(buf,strg.buf);
}

String::String(char chr, int k) {
	buf = new char[k];

	for (int index = 0; index < k; index++) {
		buf[index] = chr;
	}

	buf[k] = '\0';
	length = strlen(buf);
}

String& String::operator=(const String& strg) {
	strcpy(buf, strg.buf);
	length = strlen(strg.buf);

	return *this;
}

String& String::operator=(const char* chr) {
	buf = (char*) chr;
	length = int(strlen(chr));

	return *this;
}


String::~String() {
	length = 0;
}


String operator+(const String& strg1, const String& strg2)
{
	int newLength = strg1.length + strg2.length;
	String temp;
	temp.buf = new char[newLength];
	temp.length = newLength;

	for (int i = 0; i < strg1.length; i++) {
		temp.buf[i] = strg1.buf[i];
	}

	for (int j = 0, i = strg1.length; j < strg2.length; j++, i++) {
		temp.buf[i] = strg2.buf[j];
	}
	temp[newLength] = '\0';

	return temp;
}

String operator+(const String& strg1, const char* chr)
{
	int newLength = strg1.length + strlen(chr);
	String temp;
	temp.buf = new char[newLength];
	temp.length = newLength;

	for (int i = 0; i < strg1.length; i++) {
		temp.buf[i] = strg1.buf[i];
	}

	for (int j = 0, i = strg1.length; j < strlen(chr); j++, i++) {
		temp.buf[i] = chr[j];
	}
	temp[newLength] = '\0';

	return temp;
}

String operator+(const char* chr, const String& strg1)
{
	int newLength = strg1.length + strlen(chr);
	String temp;
	temp.buf = new char[newLength];
	temp.length = newLength;

	strcpy(temp.buf, chr);

	for (int j = 0, i = int(strlen(chr)); j < strg1.length; j++, i++) {
		temp.buf[i] = strg1.buf[j];
	}

	temp[newLength] = '\0';

	return temp;
}

String operator+(const String& strg1, const char ch)
{
	int newLength = strg1.length + 1;
	String temp;
	temp.buf = new char[newLength];
	temp.length = newLength;

	for (int i = 0; i < strg1.length; i++) {
		temp.buf[i] = strg1.buf[i];
	}

	temp[newLength - 1] = ch;
	temp[newLength] = '\0';

	return temp;
}

String operator+(const char chr, const String& strg1)
{
	int newLength = strg1.length + 1;
	String temp;
	temp.buf = new char[newLength];
	temp.length = newLength;

	temp[0] = chr;
	for (int i = 0, j = 1; i < strg1.length; i++, j++) {
		temp.buf[j] = strg1.buf[i];
	}

	temp[newLength] = '\0';

	return temp;
}


////////////// Comparison overloading //////////////

int operator==(const String& strg1, const String& strg2) {
	if (strcmp(strg1.buf, strg2.buf) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int operator!=(const String& strg1, const String& strg2) {
	if (strcmp(strg1.buf, strg2.buf) == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int operator< (const String& strg1, const String& strg2) {
	if (strcmp(strg1.buf, strg2.buf) < 0) {
		return 1;
	}
	else {
		return 0;
	}
	return strg1.buf < strg2.buf;
}

int operator>(const String& strg1, const String& strg2) {
	if (strcmp(strg1.buf, strg2.buf) > 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int operator<=(const String& strg1, const String& strg2) {
	if (strcmp(strg1.buf, strg2.buf) <= 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int operator>=(const String& strg1, const String& strg2) {
	if (strcmp(strg1.buf, strg2.buf) >= 0) {
		return 1;
	}
	else {
		return 0;
	}
}


///////////////////////////////////////////////////////////

char& String::operator[](int element) {
	char nothing = '\0';

	if (element < 0 || element > length) {
		cout << "Error: Index is out of range." << endl;
		return nothing;
	}

	else {
		return buf[element];
	}
}

String& String::operator+=(const String& strg) {
	int newlength = strg.length + length;
	char* temp = new char[newlength];

	for (int i = 0; i < length; i++) {
		temp[i] = buf[i];
	}

	for (int i = length, j = 0; j < strg.length; i++, j++) {
		temp[i] = strg.buf[j];
	}

	buf = new char[newlength];

	strcpy(buf, temp);
	//for (int i = 0; i < newlength; i++) {
	//	buf[i] = temp[i];
	//}


	buf[newlength] = '\0';
	length = strlen(buf);

	return *this;


}

String String::operator+() const {
	String temp;
	strcpy(temp.buf, buf);
	temp.length = length;

	for (int i = 0; i < length; i++){
		temp[i] = toupper(temp[i]);
	}

	return temp;
}

char* operator+(const String& strg, int i) {
	return &strg.buf[i];
}

char* operator+(int i, const String& strg) {
	return &strg.buf[i];
}


String& String::operator++(int val){

	char* temp = new char[length];

	for (int i = 0; i < length; i++) {
		temp[i] = buf[i] + 1;
	}

	return *this;
}

String& String::operator--(int val) {
	char* temp = new char[length];

	for (int i = 0; i < length; i++) {
		temp[i] = buf[i] - 1;
	}

	return *this;
}


String& String::operator--() {
	for (int i = 0; i < length; ++i) {
		buf[i] = buf[i] - 1;
	}

	return *this;
}


String& String::operator++() {
	for (int i = 0; i < length; ++i) {
		buf[i] = buf[i] + 1;
	}

	return *this;
}


String String::substr(int int1, int int2) {
	String temp;

	for (int i = int1, j = 0; j < int2; i++, j++) {
		temp.buf[j] = buf[i];
	}

	temp.buf[int2] = '\0';
	temp.length = strlen(temp.buf);

	return temp;
}


int String::getLength() {
	return length;
}

void String::print() {
	cout << "\"" << buf << "\"" << "  " << "Length = " << length << endl;
	csis << "\"" << buf << "\"" << "  " << "Length = " << length << endl;
}

ostream& operator<<(ostream& os, const String& strg) {
	for (int i = 0; i < strg.length; i++) {
		os << strg.buf[i];
	}

	return os;
}
