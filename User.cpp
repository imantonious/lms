
#include "User.h"

#include <string>
#include <iomanip>

using namespace std;

User::User()
{
	cout << "\n\n\n\n\t\t\t\t////////////////////////////" << endl;
	cout << "\t\t\t\t////////////////////////////" << endl;
	cout << "\t\t\t\t//     .        .         //" << endl;
	cout << "\t\t\t\t//.  LIBRARY MANAGEMENT   //" << endl;
	cout << "\t\t\t\t//       SYSTEM     .     //" << endl;
	cout << "\t\t\t\t//     .         .        //" << endl;
	cout << "\t\t\t\t////////////////////////////" << endl;
	cout << "\t\t\t\t///////////////logo by Sarah\n\n\n\n\n" << endl;
	name = " ";
	cout << "\t\t\t\tEnter your name: ";
	cin >> name;
}

User::User(string n)
{
	name = n;
}

void User::addToCart(Book book) {
	//book.setAvailability();
	cart.push_back(book);
}

int User::viewCart() {
	string bookTitle;
	string author;
	int bookCount = 0;
	
	for (int i = 0; i < cart.size(); i++) {
		bookTitle = cart[i].getTitle();
		author = cart[i].getAuthor();
		cout << "\t" << endl << i+1 << ". " << bookTitle << " - " << author;
		bookCount++;
	}
	return bookCount;	
}

string User::getName() {
	return name;
}

void User::printReceipt() {
	string title;
	string author;

	cout << setw(40) << "\n\n\n\n----------------------------------------\n\n\n\n"
		<< "Totals: \n\t";
	for (int i = 0; i < cart.size(); i++) {
		author = cart[i].getAuthor();
		title = cart[i].getTitle();
		cout << i+1 << ". " << title << "\n\t - By: " << author << endl << endl;
	}
}
User::~User()
{
}
