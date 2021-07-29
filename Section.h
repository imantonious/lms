
#ifndef SECTION_H
#define SECTION_H

#include "Author.h"

#include <string>
#include <vector>

using namespace std;

class Section
{
private:
	string name;
	// vector<Book> books;

public:
	Section();
	Section(string);
	// Section(string, Book);
	~Section();
};

#endif
