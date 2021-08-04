
#ifndef SECTION_H
#define SECTION_H

//#include "Author.h"
#include "Book.h"
#include "Magazine.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

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
	void addBook(int);
	void addBook(Book);
	void addMagazine(Magazine, string, string, string, bool);
	void viewBooks();
	int bookList();
	Book retrieveBook(int);
	void removeBook(Book, int);
	void reinsert(Book, int);
	void showUnavailableBooks();
	void writeBooks();
	// Section(string, Book);
	~Section();
};

#endif
