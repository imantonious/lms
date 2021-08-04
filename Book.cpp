
#include "Author.cpp"
#include "Book.h"

#include <iostream>
#include <string>
#include <iomanip>

Book::Book()
{
	title = "";
	author = "";
	dept = "";
	isAvailable = false;
}

Book::Book(string t, string a, string s, bool i)
{
	title = t;
	//author = Author(a, title);
	// section = Section(s);
	author = a;
	dept = s;
	isAvailable = i;
}

bool Book::getBookProps() {

	cout << setw(20) << title << "\t\t" << setw(15) << author << "\t\t";
	cout << setw(15) << "Available: " << isAvailable << endl;

	return isAvailable;
}

void Book::checkOut() {
	isAvailable = false;
	//getAvailability();
}

string Book::getTitle() {
	return title;
}

string Book::getAuthor() {
	return author;
}

void Book::setAvailability(bool userInput) {
	isAvailable = userInput;
}
bool Book::getAvailability() {
	//cout << "This is the availability: " << isAvailable << ". \n";
	return isAvailable;
}



Book::~Book()
{
}


