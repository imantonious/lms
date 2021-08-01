
#ifndef SECTION_H
#define SECTION_H

#include "Author.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Section
{
private:
	string name;
	vector<Book> books;

public:
	Section();
	Section(string);
	void getName();
	void addBook(Book);
	// Section(string, Book);
	~Section();
};

#endif
