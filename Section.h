
#ifndef SECTION_H
#define SECTION_H

#include "Author.h"
#include "Book.h"

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
	string getName();
	void addBook(Book);
	void viewBooks();
	int bookList();
	Book retrieveBook(int);
	// Section(string, Book);
	~Section();
};

#endif
