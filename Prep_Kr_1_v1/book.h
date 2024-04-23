#ifndef BOOK_H
#define BOOK_H

#include  <vector>
#include <string>
#include <iostream>


using namespace std;

class Book {
	string Book_name;
	int year;
public:
	Book(string name, int year) : Book_name(name), year(year) {}
	string getName() const;
	int getYear() const;
};

#endif