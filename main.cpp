
#include "Section.h"
#include "Section.cpp"
#include "User.h"
#include "User.cpp"
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
int displayMainMenu();
int processMainMenuSelection(int);
void studentSignin();
void adminSignin();
void loginPrompt();
Section populateLibrary(Section lib);
void popLibrary(Section& lib);
void viewDept(Section);
int checkOutBook();
Section checkOutBook(Section& lib, int); // overloaded function
void showAllSections();
int showBooksMenu();
int subMenuSelection(int);
void addBook();
void bookReturn();
void writeToFile(Section&);

User user = User(); // This probably shouldn't be global..


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

	for (int i = 0; i < SECTIONS; i++) {
		popLibrary(library[i]); 
	}


	displayWelcome();
	int userInput;
	int pos;
	Section i;
	string dept;

	do
	{
		userInput = displayMainMenu(); // TODO: shows up twice after making choice. fix
		userInput = processMainMenuSelection(userInput);
		switch(userInput) {
			case 0:
				userInput = 0;
				break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
				i = library[userInput - 1];
				dept = i.getName();
				cout << "\n\n\nThe " << dept << " Department contains the following books: \n\n";
				i.viewBooks();
				cout << endl << endl;
				break;
			case 7:
				for (int i = 0; i < SECTIONS; i++) {
					dept = library[i].getName();
					cout << "\n\n\nThe " << dept << " Department contains the following books: \n\n";
					library[i].viewBooks();
					}
				cout << endl << endl;
				break;
			case 8: 																// ADD Book to Cart option
				userInput = checkOutBook();
				library[userInput-1] = checkOutBook(library[userInput - 1], userInput);
				break;
			case 9:
			case 10: 
				userInput = showBooksMenu();//Add A Book 
				library[userInput-1].addBook(userInput);
			case 11:
				cout << "\t\nBOOK RETURN\n\n";
				userInput = showBooksMenu();
				library[userInput-1].showUnavailableBooks();
			
			case 12:
			case 13:
			case 14:
			case 15:
			case 16:
			case 17: 
				break;
		//userInput = displayMainMenu();	
		} //userInput = displayMainMenu();	
	} while (userInput != 0);
	return 0;
}

void displayWelcome()
{
	cout << "\t\t\tWelcome!" << endl;
	cout << "\tPlease enter a number from the options below." << endl;
}

int displayMainMenu()
{
	cout << "\n1. Add a Book to your Cart" << endl;
	cout << "2. Return Books" << endl; // TODO
	cout << "3. View Books by Department" << endl;
	cout << "4. Add a Book" << endl; // TODO
	cout << "5. View Books in Cart" << endl;
	cout << "0. Exit" << endl;
	cout << "\n#: ";

	int ch;
	cin >> ch;
	return ch;
}

int processMainMenuSelection(int option)
{
	int pos;

	if (option == 0)
	{
		return 0;
	}

	cout << endl << endl;

	switch (option) {
		case 1:
			return 8;
		case 2:
			//bookReturn();
			return 11;
			break;
		case 3:
			cout << "\tView Books By Department\n";
			return showBooksMenu();
		case 4:
			return 10;
		case 5:
			int cartBooks;
			int selection;

			cout << "\t" << user.getName() << "'s Cart\n";
			cartBooks = user.viewCart();
			cout << "\n" << cartBooks + 1 << ". Check out books";
			cout << "\n0. Return" << endl << endl;
			//printReceipt(); // TODO: Build the print receipt
			cout << "Make a selection: ";
			cin >> selection;

			return 100; // doesn't have to be 100.. this just gets us back to the main menu loop.
		default:
			cout << "Please enter a valid option.\n";
			break;
	}
	return 0;
}

void popLibrary(Section &section) {

	string fileName = section.getName();
	fileName += ".txt";

	fstream myfile;
	myfile.open(fileName);
	while (myfile) {
				// Initializes the variables 
		string title; 
		string author;
		string dept;
		string isAvailString;
		bool isAvailable = true;

		// Populates the variables
		getline(myfile, title, '\t');
		getline(myfile, author, '\t');
		getline(myfile, dept, '\t');
		getline(myfile, isAvailString, '\n'); // looking for a new line since bool is the last element of each books line
		//isAvailable = (isAvailString == "false") ? false : true; // sets isAvailable to type bool

		Book book = Book(title, author, dept, isAvailable);
		if (title != ""){
			section.addBook(book);
		}
	
	}
	myfile.close();	
}

int checkOutBook()
{
	string bookName;
	int dept;

	cout << "\n\n\tBOOK CHECKOUT\n\n";

	dept = showBooksMenu();

	return dept;
}

Section checkOutBook(Section &lib, int pos) {
	string section = lib.getName();
	int selection;
	Book book; 

	transform(section.begin(), section.end(), section.begin(), ::toupper); // I guess this just makes the string uppercase.

	cout << "\n\t" << section << " DEPARTMENT\n";

	lib.bookList();

	cout << "\nEnter a selection to add to cart: ";
	cin >> selection;
	if (selection != 0)
		selection--;
	else
		return lib;

	book = lib.retrieveBook(selection);

	user.addToCart(book);

	return lib; 
}

void bookReturn()
{
	return;
}

int showBooksMenu() // loop through all sections and print name of book (book.title) if it is available to checkout
{
	int option;
	cout << "1. Computer" << endl;
	cout << "2. Electrical" << endl;
	cout << "3. Civil" << endl;
	cout << "4. Electronics" << endl;
	cout << "5. Mechanical" << endl;
	cout << "6. Architecture" << endl;
	cout << "7. Magazines" << endl;
	cout << "8. View All Departments (Don't select during demo)" << endl;//TODO this doesn't work
	cout << "0. Exit" << endl << endl;
	
	cout << "\nSelect a department: ";

	if (cin >> option && option > 0 && option <= 7) {
		return subMenuSelection(option);
	}
	else {
		return 0;
	}
}

int subMenuSelection(int option) {
	return option;
}

void writeToFile(Section& section) {
	string fileName = section.getName();
	fileName += ".txt";
}

// in vscode terminal
// g++ main.cpp -o main.out
// ./main.out
