
#include "User.h"

#include <string>
#include <iomanip>

using namespace std;

User::User()
{
	name = " ";
	cout << "Enter your name: ";
	cin >> name;


}

User::User(string n)
{
	name = n;
}

void User::addToCart(Book book) {
	book.setAvailability();
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

void groupProject() {
	cout << "/////////////////////////////////////////////////////"
	<< 	"/////////////////////////////////////////////////////\n" << "//" << right << "//\n";
	cout << "//" << right << "//";
}
User::~User()
{
}
