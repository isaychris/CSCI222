#include <iostream>
#include <string>
#include <cstdlib> 
#include <fstream>
#include <sstream>
#include "Zipcode.h"
using namespace std;

extern ofstream csis;

string ZipCode::convertInt(int number)
{
	stringstream ss;	//create a stringstream
	ss << number;		//add int to the stream
	return ss.str();	//return a string
}

ZipCode::ZipCode(string pass) {
	barToZip(pass);
}

ZipCode::ZipCode(int pass) {
	zipToBar(pass);
}

void ZipCode::barToZip(string input)
{
	string zipcode = input;			//internally stored zipcode.

	string bgroup[25];				// barcode digits seperated into 5 groups.
	int group[5];

	int code[5] = { 7, 4, 2, 1, 0 }; //key for decoding
	int decode[25];					//product from digitint[] and code[]

	string digit[25];				//seperated barcode digits stored as strings
	int digitint[25];				//decoded digits stored as int

	int zipint[5];					//zipcode digits prep

	string zipcodemod = zipcode.substr(1, zipcode.size() - 2); //removing outside 1's

	//seperating digits to seperate strings.

	for (int i = 0; i < 24; i++){
		digit[i] = zipcodemod.at(i);
	}


	//convert strings digits to integer digits.
	for (int i = 0; i < 25; i++) {
		digitint[i] = atol(digit[i].c_str());
	}

	//decoding digits for each group
	decode[0] = digitint[0] * code[0];
	decode[1] = digitint[1] * code[1];
	decode[2] = digitint[2] * code[2];
	decode[3] = digitint[3] * code[3];
	decode[4] = digitint[4] * code[4];

	decode[5] = digitint[5] * code[0];
	decode[6] = digitint[6] * code[1];
	decode[7] = digitint[7] * code[2];
	decode[8] = digitint[8] * code[3];
	decode[9] = digitint[9] * code[4];

	decode[10] = digitint[10] * code[0];
	decode[11] = digitint[11] * code[1];
	decode[12] = digitint[12] * code[2];
	decode[13] = digitint[13] * code[3];
	decode[14] = digitint[14] * code[4];

	decode[15] = digitint[15] * code[0];
	decode[16] = digitint[16] * code[1];
	decode[17] = digitint[17] * code[2];
	decode[18] = digitint[18] * code[3];
	decode[19] = digitint[19] * code[4];

	decode[20] = digitint[20] * code[0];
	decode[21] = digitint[21] * code[1];
	decode[22] = digitint[22] * code[2];
	decode[23] = digitint[23] * code[3];
	decode[24] = digitint[24] * code[4];

	//adding decoded digits for zipcode digits for each group.
	group[0] = decode[0] + decode[1] + decode[2] + decode[3] + decode[4];
	group[1] = decode[5] + decode[6] + decode[7] + decode[8] + decode[9];
	group[2] = decode[10] + decode[11] + decode[12] + decode[13] + decode[14];
	group[3] = decode[15] + decode[16] + decode[17] + decode[18] + decode[19];
	group[4] = decode[20] + decode[21] + decode[22] + decode[23] + decode[24];

	//checking zipcode digits for 11's, changes to 0
	for (int i = 0; i < 10; i++) {
		if (group[i] == 11) {
			group[i] = 0;
		}
	}

	//prep for full zipcode number
	zipint[0] = group[0] * 10000;
	zipint[1] = group[1] * 1000;
	zipint[2] = group[2] * 100;
	zipint[3] = group[3] * 10;
	zipint[4] = group[4] * 1;

	//adding zipcode digits for full zipcode number.
	getzip = zipint[0] + zipint[1] + zipint[2] + zipint[3] + zipint[4]; //return
	getbar = zipcode;	//return
}

void ZipCode::zipToBar(int input) {
	int intzip = input;
	stringzip = convertInt(intzip); //conversion from int to string.

	string encode[5]; //encode array size for zipcode.
	string onedigit = "1"; //outside 1 digits

	//encoding process
	for (int b = 0; b < 5; b++) {
		if (stringzip.at(b) == '0') {
			encode[b] = "11000";
		}
		else if (stringzip.at(b) == '1') {
			encode[b] = "00011";
		}
		else if (stringzip.at(b) == '2') {
			encode[b] = "00101";
		}
		else if (stringzip.at(b) == '3') {
			encode[b] = "00110";
		}
		else if (stringzip.at(b) == '4') {
			encode[b] = "01001";
		}
		else if (stringzip.at(b) == '5') {
			encode[b] = "01010";
		}
		else if (stringzip.at(b) == '6') {
			encode[b] = "01100";
		}
		else if (stringzip.at(b) == '7') {
			encode[b] = "10001";
		}
		else if (stringzip.at(b) == '8') {
			encode[b] = "10010";
		}
		else if (stringzip.at(b) == '9') {
			encode[b] = "10100";
		}
	}

	//Stored full 27 digit barcode
	zipcode = onedigit + encode[0] + encode[1] + encode[2] + encode[3] + encode[4] + onedigit; //internally stored zipcode;

	barToZip(zipcode); // to get zipcode number.
}

int ZipCode::getZipCode() {
	return getzip;
}

string ZipCode::getBarCode() {
	return getbar;
}
