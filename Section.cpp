
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

// Section::Section(string n, Book b)
// {
// 	name = n;
// 	books.push_back(b);
// }
string Section::getName(){
	//cout << "\n\nName is: " << name << endl;
	return name;
}

void Section::addBook(Book book){
	book.getBookProps();
	books.push_back(book);
}

void Section::viewBooks(){
	cout << "-----------------------------------------------------------------";
	cout << endl << setw(20) << left << "Name\t\t" << setw(15) <<  "Author\t\t" << setw(11) << "Availability\n" << endl;
	for(int i = 0; i < books.size()-1; i++){
		//cout << "| ";
		books[i].getBookProps();
		//cout << " |";
	}
	//cout << "--------------------------------------------------";
}

void Section::bookList(){
	//Section dept;
	string bookTitle;
	string author;
	for (int i = 0; i < books.size()-1; i++){
		bookTitle = books[i].getTitle();
		author = books[i].getAuthor();
		cout << "\t" << endl << i+1 << ". " << bookTitle << " - " << author;
	}
	cout << "0. Exit" << endl << endl;
}

Section::~Section() {
};

// add book to section function from file
