
#ifndef USER_H
#define USER_H

#include "Book.h"

#include <string>
#include <iostream>

using namespace std;

class User
{
private:
	// bool isAdmin = false; //? default value
	string name;
	vector<Book> cart;
public:
	User();
	User(string);
	void addToCart(Book);
	void printReceipt();
	int viewCart();
	string getName();
	~User();
};
// yeah the setAdmin would be in the Admin . cpp file, which inherits from this but will change to true
#endif 
