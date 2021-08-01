
#include "Section.h"
#include "Section.cpp"
#include "User.h"

#include <iostream>
#include <istream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <fstream>
#include <array>

using namespace std;

// prototypes
void displayWelcome();
void displayMenu();
void displayMainMenu();
void processMainMenuSelection(int);
void studentSignin();
void adminSignin();
void loginPrompt();
Section populateLibrary(Section lib);
string *openBookFile(string);
void checkOutBook();
void showAllSections();
void showAllBooks();
void bookReturn();

int main(int argc, char const *argv[])
{

	const int SECTIONS = 6;

	// get all sections prefilled wth books
	// Section[Books] -> ComputerSection{book1, book2...etc.}
	//! edit sections to hold books
	Section Computer = Section("Computer");
	Section Electrical = Section("Electrical");
	Section Civil = Section("Civil");
	Section Electronics = Section("Electronics");
	Section Mechanical = Section("Mechanical");
	Section Architecture = Section("Architecture");

	Section library[SECTIONS] = {Computer, Electrical, Civil, Electronics, Mechanical, Architecture};
	
	for (int i = 0; i < SECTIONS; i++){
		Section lib = library[i];
		populateLibrary(lib); // ? should accept library and return it populated
	}
	displayWelcome();
	do
	{
		cout << "enters dowhile" << endl;
		displayMainMenu(); // TODO: shows up twice after making choice. fix
	} while (true);
	return 0;
}

void displayWelcome()
{
	cout << "\t\t\tWelcome!" << endl;
	cout << "\tPlease enter a number from the options below." << endl;
}

void displayMainMenu()
{
	cout << "1. Check Out a Book" << endl;
	cout << "2. Return Books" << endl;
	cout << "3. View All Books" << endl;
	cout << "0. Exit" << endl;

	int ch;
	cin >> ch;
	processMainMenuSelection(ch);
}

void processMainMenuSelection(int option)
{
	if (option == 0)
	{
		return;
	}

	cout << "option is: " << option << endl;

	switch (option)
	{
	case 1:
		checkOutBook();
		break;

	case 2:
		bookReturn(); // TODO: make this function work. (based on userID / ID#)
		break;

	default:
		cout << "Please enter a valid option.\n";
		break;
	}
}

void studentSignin()
{
	loginPrompt();
}

void loginPrompt()
{
	int userID;

	cout << "Enter the username: ";
	cin >> userID;

}

// Sections -> Computer, Electrical, Civil, Electronics, Mechanical, and Architecture
// create books in file
// Department of books would come from a file.  Computer.txt, Electrical.txt, etc.

// Still working on populateLibrary
Section populateLibrary(Section lib) 
{
	cout << "\n\nTesting the array of sections: " << "\n\t";
	lib.getName();/*
	Book book = Book("", "");
	lib.addBook(book);               We're gonna have to figure this one out.  */
	return lib;
}

void checkOutBook()
{
	cout << "\n\n\tBook Checkout:\n"
		 << "1. Enter the name of the book you would like to check out" << endl
		 << "2. View books available to check out" << endl;

	int i;
	cin >> i;
	while (i)
	{
		switch (i)
		{
			case 0:
				return;
			case 1:
				// TODO: make this function take the name of the book from the user and switch isAvailable bool to false
				cout << "checkoutBookByName();" << endl;
				i = 0; // exits loop
				break;
			case 2:
				// TODO: output all the books with isAvailable set to true.
				cout << "viewAllAvailableBooks();" << endl;
				i = 0; // exits loop
				break;
			default:
				cout << "Please enter a valid option.\n";
				break;
		}
	}
}

void bookReturn()
{
	// change
	return;
}

void showAllBooks() // loop through all sections and print name of book (book.title) if it is available to checkout
{
	return;
}


// Just testing out an iterator for reading files.
/*
string *openBookFile(string book)
{
	string *bookProps = new string[4];

	ifstream myfile;
	myfile.open(book);
	while (myfile)
	{
		string title;
		string author;
		string dept;
		bool checkedOut;

		myfile >> title >> author >> dept >> checkedOut;
	}
	myfile.close();
	return bookProps;
}

// in vscode terminal
// g++ main.cpp -o main.out
// ./main.out
*/
