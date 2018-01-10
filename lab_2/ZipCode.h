#ifndef _ZIPCODE_H
#define _ZIPCODE_H

using namespace std;

class ZipCode {
private:
	string zipcode; //internally stored zipcode as string barcode.

	int getzip;		//return variable for zipcode number
	string getbar;	//return variable for barcode
	string stringzip;	//conversion variable

	//helper functions
	string convertInt(int);
	string substr();//substring
	string size(); //size of string
	string c_str(); //c string

public:
	void barToZip(string); //converts string barcode to int zipcode
	void zipToBar(int); //converts int zipcode to string barcode.
	ZipCode(int); //constructor for int zipcode, uses zipToBar().
	ZipCode(string); //constructor for string barcode, uses barToZip();

	//returns
	int getZipCode(); //returns int zipcode
	string getBarCode(); //returns  string barcode
};

#endif