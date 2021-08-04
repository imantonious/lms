#ifndef MAGAZINE_H
#define MAGAZINE_H

class Magazine :  Book {
	public:
		string title;
		string author;
		string dept;
		Magazine(string, string, string, bool);
		bool getBookProps();	
		~Magazine(); // Destructor
};

#endif