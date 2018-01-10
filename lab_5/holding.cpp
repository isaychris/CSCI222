// holding.cpp

#include "holding.h"

Holding::Holding(const Holding& hold)//holding copy constructor
{
	number = hold.number;

	title = new char[strlen(hold.title + 1)];
	strcpy(title, hold.title);
}

Holding::Holding(char* name, int p_number)
{
	number = p_number;

	title = new char[strlen(name) + 1];

	for (int i = 0; i < strlen(name); i++)
	{
		title[i] = name[i];
	}

	title[strlen(name)] = '\0';
}

Holding::~Holding()
{
	delete[] title;
	number = 0;
}


