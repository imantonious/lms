
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
	//viewBooks();
	//book.setAvailability(); //TODO : not changing in library, or in books, fix if can
}

void Section::viewBooks() {
	cout << "-----------------------------------------------------------------";
	cout << endl << setw(20) << left << "Name\t\t" << setw(15) << "Author\t\t" << setw(11) << "Availability\n" << endl;
	
	for(int i = 0; i < books.size(); i++) {
		bool isAvail = books[i].getBookProps();
	}
}

int Section::bookList() {
	//Section dept;
	string bookTitle;
	string author;
	int bookCount = 0;

	for (int i = 0; i < books.size(); i++) {
		bookTitle = books[i].getTitle();
		author = books[i].getAuthor();
		if (books[i].getAvailability() == true){
			cout << "\t" << endl << i+1 << ". " << bookTitle << " - " << author;
		}
		bookCount++;
	}
	cout << "\n0. Return" << endl << endl;
	return bookCount;
}

Book Section::retrieveBook(int i){
	books[i].checkOut();
	return books[i];
}

void Section::removeBook(Book book, int pos){
	books.erase (books.begin() + pos);
}

void Section::reinsert(Book book, int pos){
	books.erase (books.begin() + pos);
	addBook(book);
}

Section::~Section() {
};

