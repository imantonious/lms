
#include "User.h"

#include <string>

using namespace std;

User::User()
{
	//name = " ";
	cout << "Enter your name: ";
	cin >> name;

}

User::User(string n)
{
	name = n;
}

void User::addToCart(Book book){
	cart.push_back(book);
}

User::~User()
{
}
