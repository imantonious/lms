
#include "Section.h"
#include "Section.cpp"
#include "User.h"
#include "Book.h"
#include "Book.cpp"

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
void openBookFile(Section);
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
		populateLibrary(lib); 
		lib.viewBooks();// ? should accept library and return it populated
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
	case 3:
		showAllBooks();

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

Section populateLibrary(Section lib) 
{

	string fileName = lib.getName();
	fileName += ".txt";

	
	fstream myfile;
	myfile.open(fileName);
	while (myfile)
	{
		string title;
		string author;
		string dept;
		bool isA = true;
		string checkedOut;

		//line = myfile.getline();
		while(myfile){
			getline(myfile, title, '\t');
			getline(myfile, author, '\t');
			getline(myfile, dept, '\t');
			getline(myfile, checkedOut, '\n');
		    //TODO For some reason, there's always one additional entry. Not sure how to end myfile earlier.
			
			/*cout << "\n\nTesting title: " << title << endl;
			cout << "Testing author: " << author << endl;
			cout << "Testing bool (though it's really a string): " << checkedOut << endl << endl; */
			
			Book book = Book(title, author, dept, isA);
			//book.getBookProps();
			lib.addBook(book);
		}
	}
	myfile.close();

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
	/*
	for (int i = 0; i < SECTIONS; i++){
		Section lib = library[i];
		populateLibrary(lib); 
		lib.viewBooks();// ? should accept library and return it populated
	}
	*/
}


// Just testing out an iterator for reading files.

void openBookFile(Section dept)
{
	// I don't think this is needed
}

// in vscode terminal
// g++ main.cpp -o main.out
// ./main.out
