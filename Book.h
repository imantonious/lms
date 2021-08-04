
#ifndef BOOK_H
#define BOOK_H

#include "Author.h"
#include "Section.h"

#include <string>
#include <iostream>

using namespace std;

class Book
{
private:
	string title;
	// Author author;
	string author;
	bool isAvailable;
	string dept;

public:
	Book();
	//Book(string, string);
	// Book(string, Author);
	//Book(string, string, string);
	Book(string, string, string, bool);
	void checkOut();
	bool getBookProps();
	string getTitle();
	string getAuthor();
	void setAvailability();
	bool getAvailability();
	~Book();

};
#endif
