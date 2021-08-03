
#include "Section.h"

#include <string>
#include <iomanip>

using namespace std;

Section::Section()
{
	name = "";
}

Section::Section(string n)
{
	name = n;
}

string Section::getName() {
	return name;
}

void Section::addBook(Book book) {
	books.push_back(book);
	book.setAvailability(); //TODO : not changing in library, or in books, fix if can
}

void Section::viewBooks() {
	cout << "-----------------------------------------------------------------";
	cout << endl << setw(20) << left << "Name\t\t" << setw(15) << "Author\t\t" << setw(11) << "Availability\n" << endl;
	for(int i = 0; i < books.size() - 1; i++) {
		bool isAvail = books[i].getBookProps();
	}
}

int Section::bookList() {
	//Section dept;
	string bookTitle;
	string author;
	int bookCount = 0;

	for (int i = 0; i < books.size() - 1; i++) {
		bookTitle = books[i].getTitle();
		author = books[i].getAuthor();
		cout << "\t" << endl << i+1 << ". " << bookTitle << " - " << author;
		bookCount++;
	}
	cout << "\n0. Return" << endl << endl;
	return bookCount;
}

Book Section::retrieveBook(int i){
	return books[i];
}

Section::~Section() {
};

