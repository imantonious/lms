
#include "Section.h"
#include "Section.cpp"
#include "User.h"

#include <iostream>
#include <istream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

// prototypes
void displayWelcome();
void displayMenu();
void displayMainMenu();
void processMainMenuSelection(int);
void studentSignin();
void adminSignin();
void loginPrompt();
void populateLibrary(int);
string *openBookFile();
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

	Section library[SECTIONS] = { Computer, Electrical, Civil, Electronics, Mechanical, Architecture };
	/*
	Section * lib;
	Section lll;
	cout << "Library is: " << library << endl;
	lib = library;
	
	Section *ptrLib;
	ptrLib = library;

	cout << ptrLib;
	//cout << &lib[0];
*/
	populateLibrary(SECTIONS);
	displayWelcome();
	do
	{
		cout << "enters dowhile"<< endl;
		displayMainMenu(); //TODO: shows up twice after making choice. fix
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
	
	//char ch = '0';
	int ch;
	cin >> ch;
	processMainMenuSelection(ch);
}

/*
void displayLoginMenu()
{
	cout << endl;
	cout << "1. Sign in as Student" << endl;
	//cout << "2. Sign in as Admin" << endl;
	cout << "0. EXIT" << endl;
	cout << "Option: ";
}
*/

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
		checkOutBook(); //TODO: make this function work. (based on userID / ID#)
		break;

	case 2:
		bookReturn(); //TODO: make this function work. (based on userID / ID#)
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

void adminSignin()
{	
	bool pwIsValid;
	cout << "FUCK";
}

void loginPrompt()
{
	int userID;
	// char passWord[8];

	cout << "Enter the username: ";
	cin >> userID;
	
	// cout << "\nEnter the password: ";
	// cin >> passWord;
	//return passWord;
}


// Sections -> Computer, Electrical, Civil, Electronics, Mechanical, and Architecture
// create books in file
// Department of books would come from a file.  Computer.txt, Electrical.txt, etc. 
void populateLibrary(int a){
	const char *departments[a] = {"Architecture.txt", "Civil.txt", "Computer.txt", "Electrical.txt", "Electronics.txt", "Mechanical.txt"};
	
	//string departments["Architecture.txt", "Civil.txt", "Computer.txt", "Electrical.txt", "Electronics.txt", "Mechanical.txt"];

	for (int i = 0 ; i < a; i++){
			//cout << departments[i];

		ifstream myfile;
		myfile.open(departments[i]); 
		*openBookFile();

		myfile.close();
	}
}

void checkOutBook() {
	// show menu want to see sections, allbooks
	// showAllSections();
	// showAllBooks();
	cout << "\nEnter an option: \n"
		<< "1. " << endl
		<< "2. " << endl;

	
	return;
}

void bookReturn(){
	// change
	return;
}

void showAllBooks(){

	// loop through all sections and print name of book (book.title) if it is available to checkout
	
	return;
}

string *openBookFile(){	
	
}
// g++ main.cpp -o main.out
// then ./main.out
