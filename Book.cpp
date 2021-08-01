
#include "Section.cpp"
#include "Author.cpp"
#include "Book.h"

#include <iostream>
#include <string>

Book::Book()
{
	title = "";
	author = "";//Author("");
	isAvailable = true;
}

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

Book::~Book()
{
}


