#include "Magazine.h"
#include "Book.h"

#include <iostream>

Magazine::Magazine(string t, string a, string i, bool b){
	title = t;
	author = a;
	dept = i;
	isAvailable = b;
}

bool Magazine::getBookProps(){

	cout << setw(20) << Book::title << "\t\t" << setw(15) << author << "\t\t";
	cout << setw(15) << "Available: " << isAvailable << endl;

	return isAvailable;
}

Magazine::~Magazine() {

}