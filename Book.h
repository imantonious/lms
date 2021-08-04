
#ifndef BOOK_H
#define BOOK_H

//#include "Author.h"
#include "Section.h"

#include <string>
#include <iostream>

using namespace std;

class Book
{
protected:
	string title;
	// Author author;
	string author;
	bool isAvailable;
	string dept;

public:
	Book();
	Book(string, string, string, bool);
	void checkOut();
	virtual bool getBookProps();
	string getTitle();
	string getAuthor();
	void setAvailability(bool);
	bool getAvailability();
	~Book();
};
#endif
