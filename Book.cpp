
#include "Author.cpp"
#include "Book.h"

#include <iostream>
#include <string>
#include <iomanip>

Book::Book()
{
	title = "";
	author = "";//Author("");
	dept = "";
	isAvailable = true;
}
/*
Book::Book(string t, string a)
{
	title = t;
	//author = Author(a);
	author = a;
}

Book::Book(string t, string a)
{
	title = t;
	author = a;
}

Book::Book(string t, string a, string s)
{
	title = t;
	//author = Author(a, title);
	// section = Section(s);
	author = a;
}
*/
Book::Book(string t, string a, string s, bool i)
{
	title = t;
	//author = Author(a, title);
	// section = Section(s);
	author = a;
	dept = s;
	isAvailable = i;
}

string Book::getBookProps(){
	cout << setw(20) << title << "\t\t" << setw(15) << author << "\t\t";

	if (isAvailable == true){
		cout << setw(11) << "Available" << endl;
	}
	else
		cout << setw(11) << "Unavailable.";
	return title;
}

void Book::checkOut(){
	isAvailable = false;
}

string Book::getTitle(){
	return title;
}

string Book::getAuthor(){
	return author;
}

Book::~Book()
{
}


