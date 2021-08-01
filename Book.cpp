
#include "Author.cpp"
#include "Book.h"

#include <iostream>
#include <string>

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

void Book::getBookProps(){
	cout << "\nThe title of this book is: " << title << endl;
	cout << "The author is: " << author << endl;
	cout << "The department is: " << dept << endl;
}

Book::~Book()
{
}


