
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
void Section::addBook() {
	string title;
	string author;
	string dept;
	int opt;
	bool isAvailable;

	cout << "\n\n\tADD BOOK\n\nPlease enter the name of the book: ";
	cin >> title;

	cout << "\n\nEnter the Author: ";
	cin >> author;

	cout << "\n\n1. Computer" << endl;
	cout << "2. Electrical" << endl;
	cout << "3. Civil" << endl;
	cout << "4. Electronics" << endl;
	cout << "5. Mechanical" << endl;
	cout << "6. Architecture" << endl;
	cout << "7. Magazines (Don't pick this in production)" << endl;
	cout << "0. Exit" << endl << endl;

	cout << "\n\nChoose a section: ";

	cin >> opt;

	switch(opt){
		case 1: dept = "Computer";
			break;
		case 2: dept = "Electrical";
			break;
		case 3: dept = "Civil";
			break;
		case 4: dept = "Electronics";
			break;
		case 5: dept = "Mechanical";
			break;
		case 6: dept = "Architecture";
			break;
		case 7: //TODO make thing funny thing work. Supposed to 'add' magazines.
		case 0:
			break;
		default:
			cout << "\n\nInvalid Selection\n\n";
			return;
			break;
	}
	Book book = Book(title, author, dept, true);
	addBook(book);
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

