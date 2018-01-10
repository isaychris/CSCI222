// book.cpp

#include "book.h"
#include <fstream>

extern ofstream csis;

Book::Book(const Book& book) : Holding(book) //book copy constructor
{
	author = new char[strlen(book.author + 1)];
	strcpy(author, book.author);
}

Book::Book(char* p_title, char* p_author, int p_number) : Holding(p_title, p_number)
{
	author = new char[strlen(p_author) + 1];

	for (int i = 0; i < strlen(p_author); i++)
	{
		author[i] = p_author[i];
	}

	author[strlen(p_author)] = '\0';
}

void Book::print()
{
	cout << "BOOK: " << author << " \"" << title << "\" " << number << endl;
	csis << "BOOK: " << author << " \"" << title << "\" " << number << endl;
}

Book::~Book()
{
	delete[] author;
}