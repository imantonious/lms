
#include "Section.h"

#include <string>

using namespace std;



Section::Section()
{
	name = "";
}

Section::Section(string n)
{
	name = n;
}

// Section::Section(string n, Book b)
// {
// 	name = n;
// 	books.push_back(b);
// }
string Section::getName(){
	return name;
}

void Section::addBook(Book book){
	book.getBookProps();
	books.push_back(book);
}

void Section::viewBooks(){
	for(int i = 0; i < books.size(); i++){
		books[i].getBookProps();
	}
}

Section::~Section() {
};

// add book to section function from file
