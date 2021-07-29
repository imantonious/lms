
#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User
{
private:
	// bool isAdmin = false; //? default value
	string name;

public:
	User();
	User(string);
	User(string, bool); 
	~User();
};
// yeah the setAdmin would be in the Admin . cpp file, which inherits from this but will change to true
#endif 
