// recording.cpp

#include "recording.h"
#include <fstream>

extern ofstream csis;

Recording::Recording(const Recording& record) : Holding(record) //recording copy constructor
{
	performer = new char[strlen(record.performer + 1)];
	format = new char[strlen(record.format + 1)];

	strcpy(performer, record.performer);
	strcpy(format, record.format);

	return ;
}

Recording::Recording(char* p_name, char p_format, char* p_performer, int p_number) : Holding(p_name, p_number)
{
	performer = new char[strlen(p_performer) + 1];

	for (int i = 0; i < strlen(p_performer); i++)
	{
		performer[i] = p_performer[i];
	}

	performer[strlen(p_performer)] = '\0';

	//.................case switch.................//
	char option = p_format;

	switch (option) {
	default:
		cout << "[Error] Invalid format." << endl;
		break;

	case 'M': case 'm':
		format = new char[5];
		format = "MP3";
		break;

	case 'W': case 'w':
		format = new char[5];
		format = "WAV";
		break;

	case 'A': case 'a':
		format = new char[5];
		format = "AIFF";
		break;
	}
	//.................case switch.................//
}

void Recording::print()
{
	cout << "RECORDING: \"" << title << "\" " << performer << " (" << format << ") " << number << endl;
	csis << "RECORDING: \"" << title << "\" " << performer << " (" << format << ") " << number << endl;
}

Recording::~Recording()
{
	delete[] performer;
	delete[] format;
}
